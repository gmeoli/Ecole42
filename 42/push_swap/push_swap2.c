/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:09:42 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/16 20:22:58 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_direction(t_best *best, t_stack *guido, int i, int flag)
{
	if (flag == 0)
	{
		best->nb = guido->stack_b[i];
		best->dir_b = 0;
		best->mb = i;
		if (i > guido->size_b / 2)
		{
			best->dir_b = 1;
			best->mb = guido->size_b - i;
		}
	}
	else
	{
		best->na = guido->stack_a[i];
		best->dir_a = 0;
		best->ma = i;
		if (i > guido->size_a / 2)
		{
			best->dir_a = 1;
			best->ma = guido->size_a - i;
		}
	}
}

void	ft_find_na(t_stack *guido, int nb, t_best *best)
{
	int	i;
	int	j;
	int	x;

	j = guido->size_a - 1;
	i = 0;
	while (i < guido->size_a)
	{
		if (guido->stack_a[i] > nb && guido->stack_a[j] < nb)
			break ;
		if (guido->stack_a[i] == 1)
			x = i;
		if (j == guido->size_a - 1)
			j = -1;
		i++;
		j++;
	}
	if (i == guido->size_a)
		ft_direction(best, guido, x, 1);
	else
		ft_direction(best, guido, i, 1);
}

t_best	ft_best_b(t_best *best, t_stack *guido)
{
	t_best	min;
	int		i;

	min = best[0];
	i = 1;
	while (i < guido->size_b)
	{
		if (min.moves > best[i].moves)
			min = best[i];
		i++;
	}
	free (best);
	return (min);
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
			if (best[i].ma > best[i].mb)
				best[i].moves = best[i].ma;
			else
				best[i].moves = best[i].mb;
		}
		else
			best[i].moves = best[i].ma + best[i].mb;
		i++;
	}
	return (ft_best_b(best, guido));
}

void	ft_algorithm(t_stack *guido)
{
	t_best	best;

	while (guido->size_b != 0)
	{
		best = ft_move_count(guido);
		while ((guido->stack_b[0] != best.nb && guido->stack_a[0] != best.na) \
			&& (best.dir_a == 0 && best.dir_b == 0))
			ft_rr(guido, 1);
		while (guido->stack_b[0] != best.nb && best.dir_b == 0)
			ft_rb(guido, 1);
		while (guido->stack_a[0] != best.na && best.dir_a == 0)
			ft_ra(guido, 1);
		while ((guido->stack_b[0] != best.nb && guido->stack_a[0] != best.na) \
			&& (best.dir_a == 1 && best.dir_b == 1))
			ft_rrr(guido, 1);
		while (guido->stack_b[0] != best.nb && best.dir_b == 1)
			ft_rrb(guido, 1);
		while (guido->stack_a[0] != best.na && best.dir_a == 1)
			ft_rra(guido, 1);
		ft_pa(guido, 1);
	}
	ft_algorithm_2(guido);
}
