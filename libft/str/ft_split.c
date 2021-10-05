/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:00:08 by mdaan         #+#    #+#                 */
/*   Updated: 2021/05/18 18:30:01 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	while (str[i])
	{
		if (!(c == str[i]) && (str[i + 1] == '\0' || (c == str[i + 1])))
			word_count++;
		i++;
	}
	return (word_count);
}

static char	**ft_make_array(char const *s, char c)
{
	char	**array;
	int		word_count;

	word_count = ft_count_words(s, c);
	array = (char **)ft_calloc((word_count + 1), sizeof(char *));
	if (!array)
		return (free_2darray(array));
	return (array);
}

static char	**ft_make_word(char const *s, char c, char **array)
{
	int		i;
	int		word_len;
	int		word_index;
	char	*word;

	i = 0;
	word_index = 0;
	while (s[i])
	{
		if (((s[0] != c && i == 0)) || (s[i] != c && s[i - 1] == c))
		{
			word_len = 0;
			while (s[i + word_len] != c && s[i + word_len])
				word_len++;
			word = ft_substr(s, i, word_len);
			if (!word)
				return (free_2darray(array));
			array[word_index] = word;
			word_index++;
		}
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = ft_make_array(s, c);
	if (!(array))
		return (NULL);
	array = ft_make_word(s, c, array);
	if (!(array))
		return (NULL);
	return (array);
}
