/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:56:51 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:23:47 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Iterates the list ’lst’ and applies the function
**	’f’ to the content of each element. Creates a new
**	list resulting of the successive applications of
**	the function ’f’. The ’del’ function is used to
**	delete the content of an element if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_next;

	if (!lst)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	while (lst->next)
	{
		lst = (lst)->next;
		new_next = ft_lstnew(f(lst->content));
		if (!new_next)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_next);
	}
	return (new_lst);
}
