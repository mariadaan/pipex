/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:57:11 by mdaan         #+#    #+#                 */
/*   Updated: 2020/11/05 14:09:28 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The bzero() function writes n zeroed bytes (\0) to the string s.
**	If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
