#include "pipex.h"

// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/wc file_out
// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/grep gewoon file_out

//./pipex file_in cat /usr/bin/grep FANTASTISCH file_out

	// fd[0]		->	read
	// fd[1]		->	write

// ./pipex file_in "cat -e" "grep gewoon" file_out


// void	message(int index)
// {
// 	char *messages[5];

// 	messages[0] = "no such file or directory: ";
// 	messages[1] = "no such file or directory: ";

// }

/*
	Find the path to cmd (command we want to execute)
	and return as a string in format "/usr/bin/grep"
*/
char	*find_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*path;
	int		path_count;
	int		path_index;
	int		i;

	// zoeken naar PATH in envp, dan splitten door ':', dan in elke map zoeken naar naam vd cmd
	path_index = get_str_index(envp, "PATH=");
	if (path_index < 0)
		return (NULL);
	paths = ft_split(envp[path_index] + 5, ':');
	path_count = ft_count_rows(paths);
	i = 0;
	while (i < path_count)
	{
		path = ft_concat_three(paths[i], "/", cmd);
		if(access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	double_error_msg("command not found", cmd, 2);
	return (NULL);
}


/*
	Execute first command with given flags and file_in as standard input.
	Does not write output to standard output, but to fd[1] (write end of the pipe).
	This output will be input to the second command, as a pipe would function.
*/
int		child_one(t_args *args, int fd[2], char *envp[])
{
	int		fd_in;

	if (!(args->file_in))
		exit(2);
	fd_in = open(args->file_in, O_RDONLY);
	if (fd_in < 0)
		error_msg("input file could not be opened", 2);
	close(fd[0]);
	dup2(fd_in, STDIN_FILENO); // Use file_in instead of standard input
	dup2(fd[1], STDOUT_FILENO); // Write to fd[1] instead of standard output
	close(fd[1]); // close 1 because it was duplicated and we dont need 2
	execve(args->path_cmd_1, args->full_cmd_1, envp);
	exit_msg("could not execve child 1", 2);
	return (2);
}

int		child_two(t_args *args, int fd[2], char *envp[])
{
	int		fd_out;

	fd_out = open(args->file_out, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd_out < 0)
		exit_msg("output file could not be opened", 2);
	dup2(fd[0], STDIN_FILENO); // read input from fd[0]
	dup2(fd_out, STDOUT_FILENO); // output naar file_out
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	// print_info(args);
	execve(args->path_cmd_2, args->full_cmd_2, envp); // end of child process, replaced by exec process
	exit_msg("could not execve child 2", 2);
	return (2);
}

int	parse_input(t_args *args, char *argv[], char *envp[])
{
	args->file_in = argv[1];
	if(access(args->file_in, F_OK) != 0) // check if file_in exists!
	{
		double_error_msg("no such file or directory", args->file_in, 0);
		args->file_in = NULL;
	}
	args->file_out = argv[4]; // doesnt have to be checked bc file is made when it doesnt exist
	args->full_cmd_1 = ft_split(argv[2], ' ');
	args->full_cmd_2 = ft_split(argv[3], ' ');
	args->path_cmd_1 = find_path((args->full_cmd_1)[0], envp);
	args->path_cmd_2 = find_path((args->full_cmd_2)[0], envp);
	return (0);
}

void	wrap_up(int *fd, t_args *args, int pid1, int pid2)
{
	close(fd[0]);
	close(fd[1]);
	free_2darray(args->full_cmd_1);
	free_2darray(args->full_cmd_2);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	parent(int pid1, int pid2)
{
	int	wstatus;
	int status_code;

	waitpid(pid1, &wstatus, 0);
	waitpid(pid1, &wstatus, 0);

	if (WIFEXITED(wstatus))
	{
		printf("executed normally");
		status_code = WEXITSTATUS(wstatus); //
		if (status_code == 0)
			printf("success");
		else
			printf("fail");
	}
	printf("fail");
}

void	pipe_simulator(t_args *args, char **envp)
{
	int		fd[2];
	int		pid1;
	int		pid2;

	if (pipe(fd) == -1)
		exit_msg("Could not open fd's with pipe", 2);
	pid1 = fork();
	if (pid1 == -1)
		exit_msg("First fork unsuccesful", 2);
	if (pid1 == CHILD_PID) // child process 1 (cat)
		child_one(args, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		exit_msg("Second fork unsuccesful", 2);
	if (pid2 == CHILD_PID) // child process 2 (grep)
	{
		waitpid(pid1, NULL, 0);
		child_two(args, fd, envp);
	}
	parent(pid1, pid2);
	wrap_up(fd, args, pid1, pid2);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_args	args;

	if (argc <= 4)
		exit_msg("Incorrect arguments. Run in following format: ./pipex "
					"file_in \"cmd flags\" \"cmd flags\" file_out", 2);
	parse_input(&args, argv, envp);
	pipe_simulator(&args, envp);
	return (0);
}


/*
	EXIT CODES:
	0 succes
	2 error

	Exit Code Number	Meaning
	1					catchall for general errors
	2					misuse of shell builtins, according to Bash documentation	
	126					command invoked cannot execute
	127					"command not found"

	< file_in ls -l | wc -l > outfile
	./pipex file_in "ls -l" "wc -l" outfile2


*/