/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:40:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/11 17:29:40 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	guido;

	if (ac == 2)
	{
		guido.stack_a = (int*)malloc(sizeof(int) * ac - 1);
		guido.stack_b = (int*)malloc(sizeof(int) * ac - 1);
		guido.size_a = (int)malloc(sizeof(int) * ac - 1);
		guido.size_b = 0;
	}
}
