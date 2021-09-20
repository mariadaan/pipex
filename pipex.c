#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

// gcc pipex.c -o pipex && ./pipex file_in /bin/cat /usr/bin/wc file_out

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
	char	*filename;
	char	*cmd;
	int		fd;

	if (argc <= 4)
		return (error_msg("pls provide 4 arguments"));
	
	filename = argv[1];
	cmd = argv[2];

	int pid = fork();
	if (pid == 0) // child
	{
		filename = argv[1];
		cmd = argv[2];
		printstr("1filename", filename);
		printstr("1cmd", cmd);
		printf("\n");
	}
	else
	{
		wait(NULL);
		cmd = argv[3];
		filename = argv[4];
		printstr("2filename", filename);
		printstr("2cmd", cmd);
		printf("\n");
		fd = open(filename, O_WRONLY);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}

	printstr("filename", filename);
	printstr("cmd", cmd);
	printf("\n");

	
	char* argvec[] = { cmd, filename, NULL };
	printf("pid: %d\n", pid);
	if (execve(cmd, argvec, envp) == -1)
		perror("Could not execve");

	return (0);
}

/*
	$PATH splitten dubbele punten
	elke folder door en zoeken naar executable
*/