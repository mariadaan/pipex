/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:59:19 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:23:52 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Counts the number of elements in a list.
*/

int	ft_lstsize(t_list *lst)
{
	int	num;

	if (!lst)
		return (0);
	num = 1;
	while (lst->next != 0)
	{
		num++;
		lst = lst->next;
	}
	return (num);
}
