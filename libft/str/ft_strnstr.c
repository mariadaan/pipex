/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:01:54 by mdaan         #+#    #+#                 */
/*   Updated: 2020/11/06 12:41:29 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The strnstr() function locates the first occurrence of the null-ter-
**	minated string needle in the string haystack, where not more than len
**	characters are searched.  Characters that appear after a `\0' charac-
**	ter are not searched.
**
**	Returns:
**	a pointer to the first character of the needle in haystack
**	if needle is not in haystack, NULL is returned
**	if needle is empty string, haystack is returned
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	size_t	i;
	size_t	needle_len;

	if (!*needle)
		return ((char *)haystack);
	hay = (char *)haystack;
	needle_len = ft_strlen(needle);
	i = 0;
	while (*hay && i < len)
	{
		if (*hay == *needle && i + needle_len <= len)
			if (!ft_strncmp(hay, needle, needle_len))
				return (hay);
		hay++;
		i++;
	}
	return (NULL);
}
