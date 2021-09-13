#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


// fork
/*
	id == 0 -> child process
	id > 0 -> main process
*/
int	main(int argc, char* argv[])
{
	int id = fork();
	if (id == 0)
	{
		printf("child\n");
	}
	else
	{
		fork();
	}
	printf( "Hello world %d\n", id);
	return (0);

}
