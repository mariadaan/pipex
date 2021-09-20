#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// execve
// library unistd

/*
	int execve(const char *pathname, char *const argv[], char *const envp[]);

	- pathname = binary executable
	- argv = an array of pointers to strings passed to the new program
	as its command-line arguments.  By convention, the first of these
	strings (i.e., argv[0]) should contain the filename associated
	with the file being executed.  The argv array must be terminated
	by a NULL pointer.  (Thus, in the new program, argv[argc] will be
	NULL.)
	- envp = an array of pointers to strings, conventionally of the
	form key=value, which are passed as the environment of the new
	program.  The envp array must be terminated by a NULL pointer.
	execve() executes the program referred to by pathname.  This
	causes the program that is currently being run by the calling
	process to be replaced with a new program, with newly initialized
	stack, heap, and (initialized and uninitialized) data segments.
	
	the program that called execve is replaced by the new program (first argument)
	A call to execve replaces the current process image with a new process image. 
	The full call is execve(path, argv, env). The second argument provides the process’s
	argument array (the argv seen in the second argument to main in the ./sub program).
	The third argument provides the process’s environment (the environ seen by the ./sub program).
*/

#include <stdio.h>
#include <unistd.h>
int main(void) {
  printf("Main program started\n");
  char* argv[] = { "jim", "jams", NULL };
  char* envp[] = { "some", "environment", NULL };
  if (execve("./test.exe", argv, envp) == -1)
    perror("Could not execve");
	printf("Hallo?");
  return 1;
}

// 
// int	main(int argc, char* argv[])
// {
	// char cmd[] = "/bin/ls";
	// char *arg_vec[] = {"ls", NULL};
	// char *en_vec[] = {NULL};
// 
// 
	// printf("start of execve call %s: \n", cmd);
	// printf("---------------------\n");
	// if (execve(cmd, arg_vec, en_vec) != -1)
	// {
		// printf("couldnt execute");
	// }
	// printf( "Hello world\n");
	// return (0);
// 
// }