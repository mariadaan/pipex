#include <stdio.h>

int main(int argc, char *argv[], char* envp[])
{
	printf("Sub program started with args: %s, %s\n", argv[0], argv[1]);
	printf("Sub program environment: %s, %s\n", envp[0], envp[1]);
	// printf("test\n");
	return (0);
}