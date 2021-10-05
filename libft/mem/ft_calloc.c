/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:57:20 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:24:12 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The calloc() function allocates memory for count objects that are size
**	bytes of memory each. The allocated memory is filled with bytes of
**	value zero.
**
**	Returns:
**	if succesful, a pointer to the allocated memory
**	if error, NULL pointer
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
