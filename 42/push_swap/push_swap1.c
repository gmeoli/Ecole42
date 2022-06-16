/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:21:49 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/16 20:22:10 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm_2(t_stack *guido)
{
	int	i;

	i = 0;
	while (guido->stack_a[i] != 1)
		i++;
	while (guido->stack_a[0] != 1 && i <= guido->size_a / 2)
		ft_ra(guido, 1);
	while (guido->stack_a[0] != 1 && i > guido->size_a / 2)
		ft_rra(guido, 1);
}
