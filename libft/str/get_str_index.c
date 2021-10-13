#include "libft.h"

/*
	Find index of row in array that starts with str
*/
int	get_str_index(char **array, char *str)
{
	int	i;
	int	rows;

	i = 0;
	rows = ft_count_rows(array);
	while (i < rows)
	{
		if (ft_strncmp(array[i], str, 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}
