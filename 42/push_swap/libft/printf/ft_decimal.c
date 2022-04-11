/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:02:40 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/11 16:34:26 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal(int x)
{
	int	count;

	count = 0;
	if (x == -2147483648)
	{
		count = write(1, "-2147483648", 11);
		return (count);
	}
	if (x < 0)
	{
		count += write(1, "-", 1);
		x *= -1;
	}
	if (x >= 10)
	{
		count += ft_decimal(x / 10);
		x = x % 10;
	}
	if (x < 10)
		ft_putchar(x + 48);
	return (count + 1);
}
