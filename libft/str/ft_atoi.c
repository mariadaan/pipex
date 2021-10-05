/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 19:45:45 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:29:53 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**	The atoi() function converts the number in str to int representation.
**
**	Returns:
**	int value
*/

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long int	res;
	int					i;
	int					sign;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[0]))
		str++;
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '+' || str[0] == '-')
		str++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
