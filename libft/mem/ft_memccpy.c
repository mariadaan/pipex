/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:58:48 by mdaan         #+#    #+#                 */
/*   Updated: 2021/10/13 17:37:43 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The memccpy() function copies up to n bytes from src to dst.
**	If the character c occurs in the string src, the copy stops. The copy
**	does include the character c.
**
**	When source and destination strings overlap, behavior is undefined.
**
**	Returns:
**	a pointer to the byte after the first c in the string dst
**	if c not in string, return NULL pointer
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			return (((unsigned char *)dst + i + 1));
		}
		i++;
	}
	return (NULL);
}
