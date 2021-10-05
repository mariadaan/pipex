/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 22:29:43 by mdaan         #+#    #+#                 */
/*   Updated: 2020/11/05 16:18:49 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Deletes and frees the given element and every successor of that element,
**	using the function ’del’ and free(3).
**	Finally, the pointer to the list must be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
