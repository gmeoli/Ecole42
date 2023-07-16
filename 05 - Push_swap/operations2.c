/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:51:54 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/18 15:02:15 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *guido, int can_print)
{
	int	i;
	int	backup;

	if (guido->size_a == 1)
		return ;
	else if (guido->size_a == 0)
		ft_error();
	backup = guido->stack_a[0];
	i = 0;
	while (i < guido->size_a - 1)
	{
		guido->stack_a[i] = guido->stack_a[i + 1];
		i++;
	}
	guido->stack_a[i] = backup;
	if (can_print)
		ft_printf("ra\n");
}

void	ft_rb(t_stack *guido, int can_print)
{
	int	i;
	int	backup;

	if (guido->size_b == 1)
		return ;
	else if (guido->size_b == 0)
		ft_error();
	backup = guido->stack_b[0];
	i = 0;
	while (i < guido->size_b - 1)
	{
		guido->stack_b[i] = guido->stack_b[i + 1];
		i++;
	}
	guido->stack_b[i] = backup;
	if (can_print)
		ft_printf("rb\n");
}

void	ft_rr(t_stack *guido, int can_print)
{
	ft_ra(guido, FALSE);
	ft_rb(guido, FALSE);
	if (can_print)
		ft_printf("rr\n");
}

void	ft_rra(t_stack *guido, int can_print)
{
	int	i;
	int	backup;

	if (guido->size_a == 1)
		return ;
	else if (guido->size_a == 0)
		ft_error();
	i = 0;
	while (i < guido->size_a)
	{
		backup = guido->stack_a[i];
		i++;
	}
	i = guido->size_a;
	while (i > 0)
	{
		guido->stack_a[i] = guido->stack_a[i - 1];
		i--;
	}
	guido->stack_a[0] = backup;
	if (can_print)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack *guido, int can_print)
{
	int	i;
	int	backup;

	if (guido->size_b == 1)
		return ;
	else if (guido->size_b == 0)
		ft_error();
	i = 0;
	while (i < guido->size_b)
	{
		backup = guido->stack_b[i];
		i++;
	}
	i = guido->size_b;
	while (i > 0)
	{
		guido->stack_b[i] = guido->stack_b[i - 1];
		i--;
	}
	guido->stack_b[0] = backup;
	if (can_print)
		ft_printf("rrb\n");
}
