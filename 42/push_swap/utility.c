/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:32:11 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/11 19:30:48 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_allocs_struct(t_stack *guido)
{
	guido->stack_a = 0;
	guido->stack_b = 0;
	guido->size_a = 0;
	guido->size_b = 0;
}
