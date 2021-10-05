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