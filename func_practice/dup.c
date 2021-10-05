#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

/*
	fd		file
	0		STDIN
	1		STDOUT
	2		STDERROR
	>2		whatever file you want
*/

/*
	If you dup a file, you create another fd that points to the same file.
	dup2(file you wanna clone, value you want fd to have);

	so if you do value = 1, it will close STDOUT completely and open it again
	with the file you want connected to it. 

	you can print to a file instead of to the terminal with
	dup2(file, 1);
	because 1 is STDOUT.
	STDOUT_FILENO macro is more clear to use instead of 1.




*/

int	main(int argc, char *argv[])
{
	int file = open("ping_results.txt", O_WRONLY | O_CREAT, 0777);
	if (file == -1)
	{
		return (2);
	}
	int file2 = dup(file);

}