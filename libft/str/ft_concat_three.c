/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_concat_three.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:00:55 by mdaan         #+#    #+#                 */
/*   Updated: 2021/10/05 15:47:10 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Description:
**	The ft_concat_three() function puts string str1, str2 and str3 together
**	in a new string that is malloced for.
**	It guarantees NUL-termination.
**
**	Returns:
**	The concatenated string.
*/
char	*ft_concat_three(char *str1, char *str2, char *str3)
{
	int		strlen;
	char	*concat;

	if (!str1 || !str2 || !str3)
		return (NULL);
	strlen = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3) + 1;
	concat = ft_calloc(strlen, sizeof(char));
	ft_strcpy(concat, str1);
	ft_strlcat(concat, str2, strlen);
	ft_strlcat(concat, str3, strlen);
	return (concat);
}
