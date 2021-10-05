/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:59:15 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:24:53 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The memcpy() function copies n bytes from memory area src to memory
**	area dst.  If dst and src overlap, behavior is undefined.
**	Applications in which dst and src might overlap should use memmove(3)
**	instead.
**
**	Returns:
**	pointer to original start of dst
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
