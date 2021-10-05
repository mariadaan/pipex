/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 22:29:32 by mdaan         #+#    #+#                 */
/*   Updated: 2020/11/03 16:11:01 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Iterates the list ’lst’ and applies the function
**	’f’ to the content of each element.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = (lst)->next;
	}
}
