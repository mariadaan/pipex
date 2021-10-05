/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:01:35 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:32:33 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The strncmp() function compares null-terminated strings s1 and s2 up to
**	the nth character or to the NULL terminator if n is larger than the strings
**
**	Returns:
**	0 if s1 == s2
**	>0 if s1 > s2
**	<0 if s1 < s2
**	(s1[char] - s2[char] on the first char that is different)
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
