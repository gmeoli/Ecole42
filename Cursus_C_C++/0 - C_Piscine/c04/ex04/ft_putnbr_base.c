/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:22:26 by gmeoli            #+#    #+#             */
/*   Updated: 2021/12/10 16:32:27 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_calculate(int nbr, char *base, int size)
{
	unsigned int	i;
	char			a;

	if (nbr < 0)
	{
		write (1, "-", 1);
		i = nbr * -1;
	}
	else
		i = nbr;
	if (i >= (unsigned int)size)
		ft_calculate(i / size, base, size);
	a = base[i % size];
	write (1, &a, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	c;

	c = 0;
	if (check_base(base) == 1)
	{
		while (base[c] != 0)
			c++;
		ft_calculate(nbr, base, c);
	}
}
