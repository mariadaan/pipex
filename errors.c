#include "pipex.h"

void	exit_msg(char *msg, int error_code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(error_code);
}

int	error_msg(char *msg, int error_code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	return (error_code);
}

int	double_error_msg(char *msg, char *name, int error_code)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(name, STDERR_FILENO);
	return (error_code);
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