#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// execve

/*
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