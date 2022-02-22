/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:55:43 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/21 17:21:18 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_deldoubles(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
			{
				while (str[j])
				{
					str[j] = str[j + 1];
					j++;
				}
				j = i;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 3)
	{
		ft_deldoubles(av[1]);
		ft_deldoubles(av[2]);
		i = 0;
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					while (av[2][j])
					{
						av[2][j] = av[2][j + 1];
						j++;
					}
					j = i;
				}
				j++;
			}
			i++;
		}
		ft_putstr(av[1]);
		ft_putstr(av[2]);
	}
	write(1, "\n", 1);
	return (0);
}
