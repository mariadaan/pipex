#include "pipex.h"

// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/wc file_out
// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/grep gewoon file_out

//./pipex file_in cat /usr/bin/grep FANTASTISCH file_out

	// fd[0]		->	read
	// fd[1]		->	write

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


int	main(int argc, char *argv[], char *envp[])
{
	char	*param;
	char	*file_out;
	char	*cmd;
	int		fd_out;
	int		fd[2];

	if (argc <= 5)
		return (1);
	if (pipe(fd) == -1)
		return (1);

	int pid1 = fork();
	if (pid1 == -1)
		return (2);

	if (pid1 == 0) // child process 1 (cat)
	{
		param = argv[1]; // file_in
		cmd = argv[2]; // /bin/cat iets
		char **vol = ft_split(argv[2], ' ');
		cmd = find_path(vol, envp);
		// argvec moet in de volgorde {/bin/cat, flags, file_in, NULL}
		// to do: dit in goeie volgorde in een 2d array krijgen.
		char* argvec[] = { cmd, "-e", param, NULL };
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO); // takes in first id, duplicates it into second id
		close(fd[1]); // close 1 because it was duplicated and we dont need 2
		execve(cmd, argvec, envp); // end of child process, replaced by exec process
	}

	int pid2 = fork();
	if (pid2 == -1)
		return (3);
	if (pid2 == 0) // child process 2 (grep)
	{
		waitpid(pid1, NULL, 0);
		cmd = argv[3]; // /usr/bin/grep FANTASTISCH
		param = argv[4]; // moet file_out zijn!! 
		file_out = argv[5];
		fd_out = open(file_out, O_WRONLY | O_CREAT, 0777);
		// /usr/bin/grep gewoon file_out
		char *argvec[] = {cmd, param, NULL};
		dup2(fd[0], STDIN_FILENO); // ??
		dup2(fd_out, STDOUT_FILENO); // output naar file_out
		close(fd[0]);
		close(fd[1]);
		close(fd_out);
		if (execve(cmd, argvec, envp) == -1) // end of child process, replaced by exec process
			perror("Could not execve");
	}
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

/*
	$PATH splitten dubbele punten
	elke folder door en zoeken naar executable
*/