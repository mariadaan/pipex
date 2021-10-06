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
}			t_args;

void	error_msg(int error_code, char *msg);
void	print_info(t_args *args);