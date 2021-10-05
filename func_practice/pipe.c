#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


// pipe
/*
	in memory file
	file that only has a buffer that is saving memory
	you can write and read from it

	pipe() takes an array of two integers. They are the file descriptors
	for this pipe. The functions will save the fds that it opens.
	fopen opens only 1 fd, pipe opens two. 

	fd[0]		->	read
	fd[1]		->	write
	
	id == 0		->	child process
	id > 0		->	parent process
	id == -1	->	error with fork

	returns 0 if succesful, 
	returns -1 if error

	when you fork, fd's integers get copied over. 
	If you close fd in one process, it remains open in another process.
	They are independent of each other. So then you will have 4 fd's in total. 
	The code below instructs how to work with pipe and fork together.

*/
int	main(int argc, char* argv[])
{
	int fd[2];
	
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
		wait(NULL);
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("y: %d\n", y);
	}
	
	return (0);
}
