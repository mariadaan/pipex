#include "../libft.h"

/*
	Checks whether a char in s2 is in s1 and returns the
	index in s1 to first occurence.
	Return -1 if no char from s2 has been found in s1
*/
int	ft_setinset(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (ft_inset(s2, s1[i]))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
