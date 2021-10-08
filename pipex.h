#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include "libft/libft.h"

#define CHILD_PID 0

#define PROGRAM_NAME bash

typedef struct s_args {
	char*	file_in;
	char*	file_out;
	char**	full_cmd_1;
	char**	full_cmd_2;
	char*	path_cmd_1;
	char*	path_cmd_2;
}			t_args;

void	exit_msg(char *msg, int error_code);
int		error_msg(char *msg, int error_code);
int		double_error_msg(char *msg, char *name, int error_code);
void	print_info(t_args *args);