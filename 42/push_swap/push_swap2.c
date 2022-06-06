/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:09:42 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/06 18:03:52 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_direction(t_best *best, t_stack *guido, int i, int flag)
{
	if (flag = 0)
	{
		best->nb = guido->stack_b[i];
		best->dir_b = 0;
		if (i > guido->size_b)
			best->dir_b = 0;
	}
	else
	{
		best->na = guido->stack_a[i];
		best->dir_a = 0;
		best->ma = i;
		if (i > guido->size_a)
		{
			best->dir_a = 0;
			best->ma = guido->size_a - i;
		}
	}
}

void	ft_find_na(t_stack *guido, int nb, t_best *best)
{
	int	i;
	int	j;
	int	x;

	j = guido->size_a;
	i = 0;
	while (i < guido->size_a)
	{
		if (guido->stack_a[i] > nb && guido->stack_a[j] < nb)
			break ;
		if (guido->stack_a[i] == 1)
			x = i;
		if (j == guido->size_a)
			j = -1;
		i++;
		j++;
	}
	if (i == guido->size_a)
		ft_direction(best, guido, x, 1);
	else
		ft_direction(best, guido, i, 1);
}

t_best	ft_move_count(t_stack *guido)
{
	int		i;
	t_best	*best;

	best = (t_best *)malloc(sizeof(t_best) * guido->size_b);
	i = 0;
	while (i < guido->size_b)
	{
		ft_direction(&best[i], guido, i, 0);
		ft_find_na(guido, guido->stack_b[i], &best[i]);
		if (best[i].dir_a == best[i].dir_b)
		{
			if (best[i])
		}
		i++;
	}
	free(best);
}

void	ft_algorithm(t_stack *guido)
{
	t_best	best;

	while (guido->size_b != 0)
	{
		best = ft_move_count(guido);
	}
}
