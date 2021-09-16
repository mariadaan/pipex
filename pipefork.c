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
	fopen opens only 1 fd, pipe opens two. A pipe has two ends,
	so two file descriptors. They have the same contents though.

	fd[0]		->	read
	fd[1]		->	write
	
	id == 0		->	child process
	id > 0		->	parent process
	id == -1	->	error with fork

	pipe returns 0 if succesful, 
	pipe returns -1 if error
*/
int	main(int argc, char* argv[])
{
	int arr[] = {1, 2, 3, 4, 1, 2, 7, 7};
	int start;
	int end;
	int fd_1[2];
	int fd_2[2];
	int arr_size;
	int pid_1;
	int pid_2;

	arr_size = sizeof(arr) / sizeof(int);

	if (pipe(fd_1) == -1 || pipe(fd_2) == -1)
	{
		return (1);
	}
	
	pid_1 = fork();
	if (pid_1 == -1)
	{
		return (2);
	}
	if (pid_1 == 0) // child
	{
		start = 0;
		end = arr_size / 2;
	}
	else // parent
	{
		wait(NULL);
		start = arr_size / 2;
		end = arr_size;
		pid_2 = fork();
	}

	int sum = 0;
	int i;
	i = start;
	while (i < end)
	{
		sum += arr[i];
		i++;
	}

	printf("Calculated partial sum: %d\n", sum);
	
	if (pid_1 == 0) // child
	{
		close(fd_1[0]);
		write(fd_1[1], &sum, sizeof(sum)); // save child sum in fd_1[1]
		close(fd_1[1]);
	}
	else if (pid_2 == 0) // second child
	{
		close(fd_2[0]);
		write(fd_2[1], &sum, sizeof(sum)); // save child sum in fd_2[1]
		close(fd_2[1]);
	}
	else // parent
	{
		wait(NULL);
		int sum_child;
		close(fd_1[1]);
		read(fd_1[0], &sum_child, sizeof(sum_child)); // read child sum that was written in fd[0]
		close(fd_1[0]);
		int total;
		total = sum + sum_child;
		sum_child = 0;
		close(fd_2[1]);
		read(fd_2[0], &sum_child, sizeof(sum_child)); // read child sum that was written in fd[0]
		close(fd_2[0]);
		total = total + sum_child;
		printf("Calculated total sum: %d\n", total);
	}
	return (0);
}
