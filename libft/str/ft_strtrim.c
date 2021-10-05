/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:02:12 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:32:49 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	int	j;
	int	len;

	len = ft_strlen(set);
	j = 0;
	while (j < len)
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	index;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	index = 0;
	while (ft_in_set(s1[i], set))
		i++;
	index = i;
	i = ft_strlen(s1) - 1;
	while (ft_in_set(s1[i], set) && i > index)
		i--;
	trim = ft_substr(s1, index, (i - index + 1));
	return (trim);
}
