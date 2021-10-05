/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbasenbr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 14:52:22 by mdaan         #+#    #+#                 */
/*   Updated: 2021/03/18 19:29:05 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbasenbr(unsigned int num, int base)
{
	char	basestr[37];

	ft_strlcpy(basestr, "0123456789abcdefghijklmnopqrstuvwxyz", 36);
	if (num >= (unsigned int)base)
		ft_putbasenbr(num / base, base);
	ft_putchar(basestr[num % base]);
}
