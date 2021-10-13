#include "pipex.h"

/*
	Execute first command with given flags and file_in as standard input. Does
	not write output to standard output, but to fd[1] (write end of the pipe).
	This output will be input to the second command, as a pipe would function.
*/
void	child_one(t_args *args, int fd[2], char *envp[])
{
	int	fd_in;

	if (!(args->file_in))
		exit(2);
	fd_in = open(args->file_in, O_RDONLY);
	if (fd_in < 0)
		error_msg("input file could not be opened", 2);
	close(fd[0]);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(args->path_cmd_1, args->full_cmd_1, envp);
	exit(127);
}

/*
	Execute second command with given flags and fd[0] (read end of pipe)
	as standard input and file_out as standard output. Does not write
	output to standard output, but to fd[1] (write end of the pipe).
	Pipe is complete when execve is executed.
*/
void	child_two(t_args *args, int fd[2], char *envp[])
{
	int	fd_out;

	fd_out = open(args->file_out, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd_out < 0)
		exit_msg("output file could not be opened", 2);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	execve(args->path_cmd_2, args->full_cmd_2, envp);
	exit(127);
}

void	parent(int *fd, int pid1, int pid2)
{
	int	wstatus;
	int	status_code;

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		status_code = WEXITSTATUS(wstatus);
		exit(status_code);
	}
}

/*
	Create two child processes, one for each command.
	pid is the current process id. If pid equals 0, this means
	we are in a child process. If pid > 0, this means we are in
	the parent process. Child 2 waits for child 1 to finish
	execution, parent waits for both children to finish
	execution.
*/
void	pipe_simulator(t_args *args, char **envp)
{
	int		fd[2];
	int		pid1;
	int		pid2;

	if (pipe(fd) == -1)
		exit_msg("Could not open fd's with pipe", 1);
	pid1 = fork();
	if (pid1 == -1)
		exit_msg("First fork unsuccesful", 1);
	if (pid1 == CHILD_PID)
		child_one(args, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		exit_msg("Second fork unsuccesful", 1);
	if (pid2 == CHILD_PID)
	{
		waitpid(pid1, NULL, 0);
		child_two(args, fd, envp);
	}
	parent(fd, pid1, pid2);
}
