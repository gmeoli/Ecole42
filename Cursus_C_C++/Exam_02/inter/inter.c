/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:24:56 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/23 12:49:27 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_deldoubles(char *str)
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

int main(int ac, char **av)
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
					write(1, &av[1][i], 1);
					break;
				}
				j++;
			}
			i++;
		}
	}
}