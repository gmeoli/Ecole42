/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:58:20 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/15 11:28:10 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *guido, int can_print)
{
	int	i;

	if (guido->size_a < 2)
		return ;
	i = guido->stack_a[0];
	guido->stack_a[0] = guido->stack_a[1];
	guido->stack_a[1] = i;
	if (can_print)
		ft_printf("sa\n");
}

void	ft_sb(t_stack *guido, int can_print)
{
	int	i;

	if (guido->size_b < 2)
		return ;
	i = guido->stack_b[0];
	guido->stack_b[0] = guido->stack_b[1];
	guido->stack_b[1] = i;
	if (can_print)
		ft_printf("sb\n");
}

void	ft_ss(t_stack *guido, int can_print)
{
	ft_sa(guido, false);
	ft_sb(guido, false);
	if (can_print)
		ft_printf("ss\n");
}

void	ft_pa(t_stack *guido)  //DA RIVEDERE
{
	if (guido->size_b == 0)
		return ;
	guido->stack_a[0] = guido->stack_b[0];
	ft_printf("pa\n");
}

void	ft_pb(t_stack *guido) //DA RIVEDERE
{
	if (guido->size_a == 0)
		return ;
	guido->stack_b[0] = guido->stack_a[0];
	ft_printf("pb\n");
}
