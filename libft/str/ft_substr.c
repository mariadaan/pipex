/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:02:21 by mdaan         #+#    #+#                 */
/*   Updated: 2020/11/05 13:01:27 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size > len)
		size = len;
	sub = malloc(size + 1 * sizeof(char));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, size);
	sub[size] = '\0';
	return (sub);
}
