#include "pipex.h"

// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/wc file_out
// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/grep gewoon file_out

//./pipex file_in cat /usr/bin/grep FANTASTISCH file_out

	// fd[0]		->	read
	// fd[1]		->	write

// ./pipex file_in "cat -e" "grep gewoon" file_out


/* 
	Find index of row that starts with PATH=
	This is the row in the environment pointer list that includes all
	paths to folders where commands are stored.
*/
int		get_path_index(char *envp[])
{
	int i;
	int rows;

	i = 0;
	rows = ft_count_rows(envp);
	while (i < rows)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}


/*
	Find the path to the cmd (command we want to execute)
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
	// ft_put2darray(envp, ft_count_rows(envp));
	path_index = get_path_index(envp);
	if (path_index < 0)
		return (NULL);
	paths = ft_split(envp[path_index] + 5, ':');
	path_count = ft_count_rows(paths);
	i = 0;
	while (i < path_count)
	{
		path = ft_concat_three(paths[i], "/", cmd);

		// printstr("path", path);

		if(access(path, F_OK) == 0)
		{
			printstr("path", path);
			printf("GELUKT\n");
			return (path);
		}
		free(path);
		i++;
	}
	printf("NIET GELUKT\n");
	return (NULL);
}


/*
	Execute first command with given flags and the file to read from as an argument.
	Does not write output to standard output, but to fd[1] (write end of the pipe).
	This output will be input to the second command, as a pipe would function.
*/
int		child_one(int fd[2], char **full_cmd, char *filename, char *envp[])
{
	char	*path;

	path = find_path(full_cmd[0], envp);
	// argvec moet in de volgorde {/bin/cat, flags, file_in, NULL}
	// to do: dit in goeie volgorde in een 2d array krijgen.
	char* argvec[] = { path, full_cmd[1], filename, NULL };
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO); // takes in first id, duplicates it into second id
	close(fd[1]); // close 1 because it was duplicated and we dont need 2
	if (execve(path, argvec, envp) == -1) // end of child process, replaced by exec process
		perror("Could not execve");
	return (0);
}

int		child_two(int fd[2], char **full_cmd, char *filename, char *envp[])
{
	int		fd_out;
	char	*path;

	path = find_path(full_cmd[0], envp);
	fd_out = open(filename, O_WRONLY, O_TRUNC | O_CREAT, 0777);
	if (fd_out < 0)
		perror("output file could not be opened");
	// /usr/bin/grep gewoon
	char *argvec[] = {path, full_cmd[1], NULL};
	dup2(fd[0], STDIN_FILENO); // read input from fd[0]
	dup2(fd_out, STDOUT_FILENO); // output naar file_out
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	if (execve(path, argvec, envp) == -1) // end of child process, replaced by exec process
		perror("Could not execve");
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*filename;
	int		fd_out;
	int		fd[2];
	char	**full_cmd_one;
	char	**full_cmd_two;

	if (argc <= 4)
		return (1);
	if (pipe(fd) == -1)
		return (1);

	int pid1 = fork();
	if (pid1 == -1)
		return (2);

	full_cmd_one = NULL;
	full_cmd_two = NULL;
	fd_out = -1;
	if (pid1 == 0) // child process 1 (cat)
	{
		filename = argv[1]; // file_in
		// cmd = argv[2]; // cat iets
		full_cmd_one = ft_split(argv[2], ' ');
		// argvec moet in de volgorde {/bin/cat, flags, file_in, NULL}
		// to do: dit in goeie volgorde in een 2d array krijgen.

		child_one(fd, full_cmd_one, filename, envp);
	}

	int pid2 = fork();
	if (pid2 == -1)
		return (3);
	if (pid2 == 0) // child process 2 (grep)
	{
		waitpid(pid1, NULL, 0);
		filename = argv[4];
		full_cmd_two = ft_split(argv[3], ' ');
		child_two(fd, full_cmd_two, filename, envp);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	free_2darray(full_cmd_one);
	free_2darray(full_cmd_two);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

/*
	$PATH splitten dubbele punten
	elke folder door en zoeken naar executable
*/