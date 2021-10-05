/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 22:29:55 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:31:59 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The strdup() function allocates sufficient memory for a copy of the
**	string s1, does the copy (including NULL-terminator) and returns a
**	pointer to it.
**
**	Returns:
**	a pointer to the (memory allocated) copy of s1
*/

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;

	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(len * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len);
	return (s2);
}
