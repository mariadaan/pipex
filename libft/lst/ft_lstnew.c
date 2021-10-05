/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 13:36:03 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:23:43 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates (with malloc(3)) and returns a new
**	element. The variable ’content’ is initialized
**	with the value of the parameter ’content’. The
**	variable ’next’ is initialized to NULL
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}
