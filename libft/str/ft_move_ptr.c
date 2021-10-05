#include "../libft.h"

char	*ft_move_ptr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (s && *ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (c == '\0' && *ptr == '\0')
		return (ptr);
	return ((char *)s);
}
