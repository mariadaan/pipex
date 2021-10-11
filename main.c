#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_args	args;

	if (argc <= 4)
		exit_msg("Incorrect arguments. Run in following format: ./pipex "
					"file_in \"cmd flags\" \"cmd flags\" file_out", 2);

	parse_input(&args, argv, envp);
	pipe_simulator(&args, envp);
	return (0);
}