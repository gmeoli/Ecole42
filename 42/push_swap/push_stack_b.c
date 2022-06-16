/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:24:55 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/16 19:12:22 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_away(int nb, t_stack *guido)
{
	while (guido->stack_a[0] != nb)
		ft_ra(guido, TRUE);
	ft_pb(guido, TRUE);
}

void	ft_push_chunk(t_stack *guido)
{
	int	i;
	int	j;
	int	med;

	med = guido->size_a / 4;
	while (guido->size_a != guido->size_lis)
	{
		i = -1;
		while (++i < guido->size_a)
		{
			j = -1;
			while (++j < guido->size_lis)
				if (guido->stack_a[i] == guido->lis[j])
					break ;
			if (guido->stack_a[i] != guido->lis[j] && guido->stack_a[i] <= med)
			{
				ft_push_away(guido->stack_a[i], guido);
				i = -1;
			}
		}
		med += (guido->size_a + guido->size_b) / 4;
	}
}
