#include "../libft.h"

int	ft_onlydigits(char *str)
{
	while (str && *str)
	{
		if (!(ft_isdigit(*str)) && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}
