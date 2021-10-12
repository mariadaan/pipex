#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include "libft/libft.h"

#define CHILD_PID 0

typedef struct s_args {
	char*	file_in;
	char*	file_out;
	char**	full_cmd_1;
	char**	full_cmd_2;
	char*	path_cmd_1;
	char*	path_cmd_2;
	int		exit_code;
}			t_args;

/*
	pipex.c
*/
void	child_one(t_args *args, int fd[2], char *envp[]);
void	child_two(t_args *args, int fd[2], char *envp[]);
void	parent(int *fd, int pid1, int pid2);
void	pipe_simulator(t_args *args, char **envp);

/*
	parse.c
*/
char	*find_path(char *cmd, char *envp[]);
int		parse_input(t_args *args, char *argv[], char *envp[]);

/*
	errors.c
*/
void	exit_msg(char *msg, int error_code);
int		error_msg(char *msg, int error_code);
int		double_error_msg(char *msg, char *name, int error_code);
void	print_info(t_args *args);