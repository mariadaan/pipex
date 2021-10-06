
#include "pipex.h"

// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/wc file_out
// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/grep gewoon file_out

	// fd[0]		->	read
	// fd[1]		->	write

char	**save_args(int fd[], char *argv[], char *envp[], int id)
{
	char *infile;
	char **cmd;

	if (id == 1)
	{
		infile = argv[0];
		// printstr("infile", infile);
		if( access(infile, F_OK) != 0 )
		{
			printf("infile doesn't exist\n");
			return (NULL);
		}
	}
	cmd = ft_split(argv[1], ' ');
	ft_put2darray(cmd, ft_count_rows(cmd));
	if (!cmd)
		return (NULL);
	return (cmd);
}

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
char	*find_path(char **cmd, char *envp[])
{
	char	**paths;
	char	*path;
	int		path_count;
	int		path_len;
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
		// paths[i] + "/" + cmd[0]
		path_len = ft_strlen(paths[i]) + 2 + ft_strlen(cmd[0]); // + 2 voor NULL term en "/"
		path = ft_calloc(path_len, sizeof(char));
		ft_strcpy(path, paths[i]);
		ft_strlcat(path, "/", path_len);
		ft_strlcat(path, cmd[0], path_len);
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

int	command(int fd[], char *argv[], char *envp[], int id)
{
	char	**cmd;
	char	*path;
	char	*outfile;
	int		fd_out;

	printnum("id", id);
	// ft_put2darray(argv, ft_count_rows(argv));
	
	cmd = save_args(fd, argv, envp, id);
	printstr("cmd op plek 0", cmd[0]);
	printstr("cmd op plek 1", cmd[1]);
	printstr("cmd op plek 2", cmd[2]);
	path = find_path(cmd, envp);
	if (!path)
	{
		perror("path niet goed gegaan");
		return (1);
	}

	printf("TEST\n");
	if (id == 1) // cat
	{
		// close(fd[0]);
		// dup2(fd[1], STDOUT_FILENO); // takes in first id, duplicates it into second id
		// close(fd[1]); // close 1 because it was duplicated and we dont need 2
		printstr("path for exec", path);
		printf("cmd 2d array:\n");
		ft_put2darray(cmd, ft_count_rows(cmd));
		if (execve(path, cmd, envp) == -1) // end of child process, replaced by exec process
			perror("Could not execve");
	}
	if (id == 2) // grep
	{
		outfile = argv[ft_count_rows(argv) - 1];
		printstr("outfile", outfile);
		fd_out = open(outfile, O_WRONLY | O_CREAT, 0777);
		printnum("fd out", fd_out);
		dup2(fd[0], STDIN_FILENO); // ??
		dup2(fd_out, STDOUT_FILENO); // output naar file_out
		close(fd[0]);
		close(fd[1]);
		close(fd_out);
	}
	printf("TEST\n");



	return (0);
}

int	command1(int fd[], char *argv[], char *envp[])
{
	char	**cmd;
	char	*path;

	cmd = save_args(fd, argv, envp, 1);
	path = find_path(cmd, envp);
	if (!path)
		return (1);
	// char* argvec[] = { cmd[0], cmd[1], NULL };
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO); // takes in first id, duplicates it into second id
	close(fd[1]); // close 1 because it was duplicated and we dont need 2
	execve(path, cmd, envp); // end of child process, replaced by exec process
	return (0);
}

int	command2(int fd[], char *argv[], char *envp[])
{
	char	**command;
	int		fd_out;

	command = ft_split(argv[3], ' ');
	fd_out = open(argv[4], O_WRONLY | O_CREAT, 0777);
	dup2(fd[0], STDIN_FILENO); // ??
	dup2(fd_out, STDOUT_FILENO); // output naar file_out
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	execve(command[0], command, envp);
	free_2darray(command); // komt ie hier wel?
	return (0);
}
/*
	Gewenst: 2d array met [0] de command en [1] en verder de flags
	en een variabele met aantal elementen
*/
int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		pid1;
	int		pid2;

	printf("\n\n\n");
	if (argc <= 4)
		return (1);
	if (pipe(fd) == -1)
		return (2);
	pid1 = fork();
	if (pid1 < 0)
		return (3);
	if (pid1 == 0) // child process 1 (cat)
	{
		command(fd, argv + 1, envp, 1);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (4);
	if (pid2 == 0) // child process 2 (grep)
	{
		waitpid(pid1, NULL, 0);
		command(fd, argv + 2, envp, 2);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

/*
	$PATH splitten dubbele punten
	elke folder door en zoeken naar executable
*/