#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_args	args;

	args.exit_code = 0;
	if (argc <= 4)
		exit_msg("Incorrect arguments. Run in following format: ./pipex "
					"file_in \"cmd flags\" \"cmd flags\" file_out", 1);
	parse_input(&args, argv, envp);
	pipe_simulator(&args, envp);
	return (args.exit_code);
}