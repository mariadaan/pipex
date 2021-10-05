/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:14:06 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:23:36 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the last element of the list.
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
