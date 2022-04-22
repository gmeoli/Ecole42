/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:32:11 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/23 01:07:52 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_allocs_stack(t_stack *guido, int ac)
{
	guido->stack_a = (int *)malloc(sizeof(int) * ac - 1);
	guido->stack_b = (int *)malloc(sizeof(int) * ac - 1);
	guido->size_a = 0;
	guido->size_b = 0;
}

void	ft_fill_stack(t_stack *guido, char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		guido->stack_a[i] = ft_atoi(av[i]);
		if (!ft_is_nbr_int(guido->stack_a[i]))
			ft_error();
		guido->size_a++;
		i++;
	}
	if (ft_is_nbr_dup(guido))
		ft_error();
}
