#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// waitpid
/*
	wait for a specific child process to be finished before continuing with the parent process
	id ==  0 -> child process
	id > 0 -> main process

	waitpid(pid_t pid, int *stat_loc, int options)
	The pid parameter specifies the set of child processes for which to wait.  If pid is -1, the call
	waits for any child process.  If pid is 0, the call waits for any child process in the process group
	of the caller.  If pid is greater than zero, the call waits for the process with process id pid.  If
	pid is less than -1, the call waits for any process whose process group id equals the absolute value
	of pid.

	last parameter can be a flag. For example: WNOHANG will not wait, will just check the status of the
	process and save it in the second parameter *stat_loc. 
*/
int	main(int argc, char* argv[])
{
	int pid1 = fork();

	if (pid1 == -1)
	{
		printf("error creating process\n");
		return (1);
	}

	if (pid1 == 0)
	{
		sleep(4);
		printf("finished execution %d\n", getpid());
		return (0);
	}
	
	int pid2 = fork();
	if (pid1 == -1)
	{
		printf("error creating process\n");
		return (2);
	}
	if (pid2 == 0)
	{
		sleep(1);
		printf("finished execution %d\n", getpid());
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);

}
