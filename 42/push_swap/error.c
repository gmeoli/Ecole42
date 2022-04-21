/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:43:00 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/21 16:29:32 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_contains_char(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') \
				&& (av[i][j] != '-' && av[i][j] != '+' && av[i][j] != ' '))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	ft_is_nbr_int(long long int nbr)
{
	return ((nbr >= (-__INT_MAX__ - 1) && nbr <= __INT_MAX__));
}

int	ft_is_nbr_dup(t_stack *guido)
{
	int	i;
	int	j;

	i = 0;
	while (i < guido->size_a)
	{
		j = i + 1;
		while (j < guido->size_a)
		{
			if (guido->stack_a[i] == guido->stack_a[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
