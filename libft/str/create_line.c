#include "../libft.h"

char	*create_line(char *str, char *needle)
{
	char	*line;
	char	*trimmedline;
	int		index;

	line = ft_strstr(str, needle);
	if (line)
	{
		line += ft_strlen(needle);
		while (*line == ' ')
			line++;
		index = get_findex(line, '\n');
		line = ft_substr(line, 0, index);
		trimmedline = ft_strtrim(line, " ");
		free(line);
		return (trimmedline);
	}
	return (NULL);
}
