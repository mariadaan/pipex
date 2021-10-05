/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:59:28 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:25:57 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The memset() function writes n bytes of value c (converted to an
**	unsigned char) to the string b.
**
**	Returns:
**	the string b
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
