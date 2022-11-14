/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:38:09 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/11 17:04:35 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsint(unsigned int x)
{
	int	count;

	count = 0;
	if (x >= 10)
	{
		count += ft_decimal(x / 10);
		x = x % 10;
	}
	if (x < 10)
		ft_putchar(x + 48);
	return (count + 1);
}
