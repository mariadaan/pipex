#include "libft.h"

/*
	Returns: first index of c in str
*/
int	get_findex(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (-1);
}

/*
	Returns: last index of c in str
*/
int	get_lindex(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = ft_strlen(str) - 1;
	while (str[i] && str[i] != c)
		i--;
	return (i);
}
