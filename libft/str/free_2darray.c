#include "libft.h"

char	**free_2darray(char **array)
{
	int	index;

	index = ft_count_rows(array);
	while (index > 0)
	{
		free(array[index - 1]);
		index--;
	}
	free(array);
	return (NULL);
}
