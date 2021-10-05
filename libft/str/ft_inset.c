int	ft_inset(char *s1, char c)
{
	while (s1 && *s1)
	{
		if (c == *s1)
			return (1);
		s1++;
	}
	return (0);
}
