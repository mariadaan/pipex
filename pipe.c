#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


// pipe
/*
	in memory file
	id == 0 -> child process
	id > 0 -> main process
*/
int	main(int argc, char* argv[])
{
	int fd[2];
	// fd[0] - read
	// fd[1] - write
	if (pipe(fd) == -1)
	{
		printf("pipe error\n");
		return (1);
	}
	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("y: %c\n", y);
	}
	
	return (0);
}
