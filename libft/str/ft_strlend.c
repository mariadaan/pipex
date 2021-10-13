/*
**	Returns:
**	Amount of chars till the end char ('\n' in get_next_line)
*/

int	ft_strlend(const char *s, char end)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] && s[len] != end)
		len++;
	return (len);
}
