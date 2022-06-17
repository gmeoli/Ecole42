/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:17:59 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/17 16:24:41 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_special_condition(t_stack *guido)
{
	int	*ara;

	ara = guido->stack_a;
	if (ara[0] == 1 || ara[1] == 2 || ara[2] == 3)
		if (ara[2] != 5 && ara[0] != 4)
			ft_sa(guido, 1);
}
