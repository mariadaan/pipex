#include "libft.h"

void	ft_put2darray(char **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		ft_putstr_fd(array[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
