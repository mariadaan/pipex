#include "../libft.h"

int	ft_has_digit(char *str)
{
	while (str && *str)
	{
		if (ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}
