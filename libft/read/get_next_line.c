/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 15:41:37 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/22 11:13:51 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The ft_join function concatenates s1 and s2 into a new string, for which
**	memory is allocated. It copies s1 until the terminating zero, and s2
**	until the 'end' character that is given as an argument. For get_next_line,
**	this is a newline character: '\n'.
**
**	Returns:
**	- new concatenated string if successful
**	- NULL if malloc failed
*/

static char	*ft_join(char *s1, char *s2, char end)
{
	int		i;
	int		line_len;
	char	*tmp;

	if (!s2)
		return (s1);
	line_len = ft_strlend(s1, end);
	tmp = malloc(ft_strlend(s2, end) + line_len + 1);
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, s1);
	i = 0;
	while (s2[i] && s2[i] != end)
	{
		tmp[i + line_len] = s2[i];
		i++;
	}
	tmp[i + line_len] = '\0';
	free(s1);
	return (tmp);
}

/*
**	Description:
**	When called in a loop, the get_next_line function reads one line at the
**	time from the file descriptor, until the EOF is reached. The line is
**	stored in char **line.
**
**	Returns:
**	1 : A line has been read
**	0 : EOF has been reached
**	-1 : An error happened
*/

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = 0;
	ret = 1;
	while (ret > 0)
	{
		*line = ft_join(*line, buf, '\n');
		if (ft_modstr(buf, '\n'))
			return (1);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
	}
	return (ret);
}
