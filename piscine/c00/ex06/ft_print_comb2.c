/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:46:28 by gmeoli            #+#    #+#             */
/*   Updated: 2021/11/28 12:36:26 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putchar (a / 10 + 48);
			ft_putchar (a % 10 + 48);
			ft_putchar (' ');
			ft_putchar (b / 10 + 48);
			ft_putchar (b % 10 + 48);
			if (a < 98)
				write (1, ", ", 2);
			b++;
		}
		a++;
	}
}
