/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 16:50:44 by mdaan         #+#    #+#                 */
/*   Updated: 2020/11/05 15:33:00 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Takes as a parameter an element and frees the
**	memory of the element’s content using the function
**	’del’ given as a parameter and free the element.
**	The memory of ’next’ must not be freed.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
