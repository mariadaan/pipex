/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:01:12 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:32:21 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The strlen() function computes the length of the string s.
**
**	Returns:
**	number of characters in string, excluding the terminating NULL character
*/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
