/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:51:54 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/22 22:14:56 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *guido, int can_print)
{
	int	i;
	int	backup;

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
