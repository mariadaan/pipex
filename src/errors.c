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
