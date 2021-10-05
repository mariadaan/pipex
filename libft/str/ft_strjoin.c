/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:00:46 by mdaan         #+#    #+#                 */
/*   Updated: 2020/11/05 13:25:33 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	tot_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	tot_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)ft_calloc((tot_len), sizeof(char));
	if (!(s3))
		return (NULL);
	ft_strlcpy(s3, s1, (ft_strlen(s1) + 1));
	ft_strlcat(s3, s2, (tot_len));
	return (s3);
}
