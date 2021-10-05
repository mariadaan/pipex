int	ft_count_rows(char **array)
{
	int count;

	if (!array)
		return (0);
	count = 0;
	while (array[count])
		count++;
	return (count);
}
