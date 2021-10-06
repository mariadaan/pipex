#include "pipex.h"

void	error_msg(int error_code, char *msg)
{
	int	msg_len;

	if (!msg)
		msg_len = 0;
	else
		msg_len = ft_strlen(msg);
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, msg_len);
	write(STDERR_FILENO, "\n", 1);
	exit(error_code);
}

void print_info(t_args *args)
{
	printstr("file in ", args->file_in);
	printf("--------------------------------------------\n");
	printstr("file out", args->file_out);
	printf("--------------------------------------------\n");
	printstr("command 1", (args->full_cmd_1)[0]);
	printf("--------------------------------------------\n");
	printstr("command 2", (args->full_cmd_2)[0]);
	printf("--------------------------------------------\n");
	printstr("path 1", args->path_cmd_1);
	printf("--------------------------------------------\n");
	printstr("path 2", args->path_cmd_2);
	printf("--------------------------------------------\n");
}