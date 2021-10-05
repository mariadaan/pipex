/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:59:22 by mdaan         #+#    #+#                 */
/*   Updated: 2020/11/05 13:12:19 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	Does same thing as memcpy.  The memmove() function copies len bytes
**	from string src to string dst.  The two strings may overlap; the copy
**	is always done in a non-destructive manner.
**
**	Returns:
**	pointer to original start of dst
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}
