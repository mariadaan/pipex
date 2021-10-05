/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:58:58 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:24:21 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The memchr() function locates the first occurrence of char c
**	in the first n bytes of string s.
**
**	Returns:
**	a pointer to the byte in s where c is located
**	if c not in first n bytes of s, return NULL pointer
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
