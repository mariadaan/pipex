#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

// < file1 cmd1 | cmd2 > file2
// ./pipex file1 cmd1 cmd2 file2

// $> ./pipex infile ``ls -l'' ``wc -l'' outfile
// should be the same as “< infile ls -l | wc -l > outfile”

// $> ./pipex infile ``grep a1'' ``wc -w'' outfile
// should be the same as “< infile grep a1 | wc -w > outfile”

// int	dup2(int_fd, int_fd2)
// Duplicate FD to FD2, closing FD2 and making it open on the same file.

// fd[0] read
// fd[1] write

int	main(int argc, char* argv[])
{
	int fd[2];

	if (pipe(fd) == -1)
	{
		return (1);
	}
	int pid1 = fork();
	if (pid1 == -1)
	{
		return (2);
	}
	
	if (pid1 == 0) // child (ping)
	{
		// char *argv[] = {"/bin/ls", NULL};
		char *argv[] = {"ping", "-c", "5", "google.com", NULL};
		char *envp[] = {NULL};
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve("/sbin/ping", argv, envp);
	}

	int pid2 = fork();
	if (pid2 == -1)
	{
		return (3);
	}
	if (pid2 == 0) // child process 2 (grep)
	{
		char *argv[] = {"grep", "statistics", NULL};
		char *envp[] = {NULL};
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/grep", argv, envp);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}