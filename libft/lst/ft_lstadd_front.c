/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:58:22 by mdaan         #+#    #+#                 */
/*   Updated: 2020/11/03 16:08:37 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adds the element ’new’ at the beginning of the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
