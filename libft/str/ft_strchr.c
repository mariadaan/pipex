/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:00:15 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:31:07 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The strchr() function locates the first occurrence of c (converted to
**	a char) in the string pointed to by s.  The terminating null charac-
**	ter is considered to be part of the string; therefore if c is `\0',
**	the function locates the terminating `\0'.
**
**	Returns:
**	a pointer to the located character in s
**	NULL if char c not in s
*/

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (c == '\0' && *ptr == '\0')
		return (ptr);
	return (NULL);
}
