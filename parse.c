#include "pipex.h"

/*
	Find the path to cmd (command we want to execute, like "grep")
	and return as a string in format "/usr/bin/grep"
*/
char	*find_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*path;
	int		path_count;
	int		path_index;
	int		i;

	path_index = get_str_index(envp, "PATH=");
	if (path_index < 0)
		return (NULL);
	paths = ft_split(envp[path_index] + 5, ':');
	path_count = ft_count_rows(paths);
	i = 0;
	while (i < path_count)
	{
		path = ft_concat_three(paths[i], "/", cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	double_error_msg("command not found", cmd, 2);
	return (NULL);
}

/*
	Saves arguments from argv into args struct. Print error message
	if input file does not exist, but continue program.
*/
int	parse_input(t_args *args, char *argv[], char *envp[])
{
	args->file_in = argv[1];
	if (access(args->file_in, F_OK) != 0)
	{
		double_error_msg("no such file or directory", args->file_in, 1);
		args->file_in = NULL;
	}
	args->file_out = argv[4];
	args->full_cmd_1 = ft_split(argv[2], ' ');
	args->full_cmd_2 = ft_split(argv[3], ' ');
	args->path_cmd_1 = find_path((args->full_cmd_1)[0], envp);
	args->path_cmd_2 = find_path((args->full_cmd_2)[0], envp);
	return (0);
}
