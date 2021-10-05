#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


// wait
/*
	wait for child process to be finished before continuing with the parent process
	id ==  0 -> child process
	id > 0 -> main process
*/
int	main(int argc, char* argv[])
{
	int id = fork();
	int n;

	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
	int i = n;
	if (id != 0)
	{
		wait(NULL);
	}
	while (i < n + 5)
	{
		printf("%d ", i);
		i++;
	}
	if (id != 0)
		printf("\n");
	return (0);

}
