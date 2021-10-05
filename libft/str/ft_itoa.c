/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:58:03 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:30:13 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		if (n > 0)
			n = n / 10;
		else
			n = n / -10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		num;
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n;
	len = ft_get_len(n);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}
