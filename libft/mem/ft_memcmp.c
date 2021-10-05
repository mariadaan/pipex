/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:59:07 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:24:28 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The memcmp() function compares byte string s1 against byte string s2.
**	Both strings are assumed to have the same length: n bytes.
**
**	Returns:
**	zero if the two strings are identical
**	if strings are not identical, returns the difference between
**	the first two differing bytes (treated as unsigned char values)
**	Zero-length strings are always identical.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
