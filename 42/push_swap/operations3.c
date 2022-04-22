/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:07:35 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/23 01:19:54 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack *guido, int can_print)
{
	ft_rra(guido, FALSE);
	ft_rrb(guido, FALSE);
	if (can_print)
		ft_printf("rrr\n");
}
