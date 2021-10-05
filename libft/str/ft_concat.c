/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_concat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:00:55 by mdaan         #+#    #+#                 */
/*   Updated: 2021/09/22 14:42:29 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Description:
**	The ft_concat() function appends string str2 to the end of str1
**	in a new string that is malloced for.
**	It guarantees NUL-termination.
**
**	Returns:
**	The concatenated string.
*/
char	*ft_concat(char *str1, char *str2)
{
	int		strlen;
	char	*concat;

	strlen = ft_strlen(str1) + ft_strlen(str2) + 1;
	concat = ft_calloc(strlen, sizeof(char));
	ft_strcpy(concat, str1);
	ft_strlcat(concat, str2, strlen);
	return (concat);
}
