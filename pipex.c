#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/wc file_out
// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/grep gewoon file_out

	// fd[0]		->	read
	// fd[1]		->	write

int	printstr(char *name, char *str)
{
	int	ret;

	ret = 0;
	if (strlen(name) > 0)
		ret = printf("%-20s", name);
	ret += printf("%s\n", str);
	return (ret);
}


int	error_msg(char *message)
{
	printf("Error: %s\n\n", message);
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*param;
	char	*file_out;
	char	*cmd;
	int		fd_out;
	int	fd[2];

	if (argc <= 5)
		return (error_msg("pls provide 5 arguments"));

	if (pipe(fd) == -1)
		return (1);

	int pid1 = fork();
	if (pid1 == -1)
		return (2);

	if (pid1 == 0) // child process 1 (cat)
	{
		param = argv[1];
		cmd = argv[2];
		char* argvec[] = { cmd, param, NULL };
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
		cmd = argv[3];
		param = argv[4];
		file_out = argv[5];
		fd_out = open(file_out, O_WRONLY | O_CREAT, 0777);
		// /usr/bin/grep gewoon file_out
		char *argvec[] = {cmd, param, NULL};
		dup2(fd[0], STDIN_FILENO); // ??
		dup2(fd_out, STDOUT_FILENO); // output naar file_out
		close(fd[0]);
		close(fd[1]);
		close(fd_out);
		int res = execve(cmd, argvec, envp);
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