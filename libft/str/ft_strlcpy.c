/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:01:04 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:32:10 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The strlcpy() function copies up to dstsize - 1 characters from the string
**	src to dst, NUL-terminating the result if dstsize is not 0.
**	Room for the NUL-terminator should be included in dstsize.
**
**	Returns:
**	total length of string it tries to create, aka length of src.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		if (dstsize != 0)
			dst[i] = '\0';
	}
	return (ft_strlen(src));
}
