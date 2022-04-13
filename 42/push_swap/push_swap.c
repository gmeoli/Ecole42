/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:40:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/13 18:23:27 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	guido;
	int	i;

	i = 0;
	if (ac > 2)
	{
		guido.stack_a = (int*)malloc(sizeof(int) * ac - 1);
		guido.stack_b = (int*)malloc(sizeof(int) * ac - 1);
		guido.size_a = (int)malloc(sizeof(int) * ac - 1);
		guido.size_b = 0;
		ft_fill_stack(&guido, &av[1]);
		while (guido.stack_a[i])
		{
			printf("%d	", guido.stack_a[i]);
			i++;
		}
		ft_sa(&guido);
	}
}
