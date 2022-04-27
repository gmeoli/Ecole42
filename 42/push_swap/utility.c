/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:32:11 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/27 18:53:06 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_allocs_stack(t_stack *guido, int ac, char **av)
{
	guido->stack_a = (int *)malloc(sizeof(int) * ac - 1);
	guido->stack_b = (int *)malloc(sizeof(int) * ac - 1);
	guido->size_a = 0;
	guido->size_b = 0;
	ft_fill_stack(guido, av + 1);
}

void	ft_fill_stack(t_stack *guido, char **av)
{
	int			i;
	long long	check_nbr;

	if (ft_contains_char(&av[1]))
		ft_error();
	i = 0;
	check_nbr = 0;
	while (av[i])
	{
		check_nbr = ft_atoi(av[i]);
		if (!ft_is_nbr_int(check_nbr))
			ft_error();
		guido->stack_a[i] = (int)check_nbr;
		guido->size_a++;
		i++;
	}
	if (ft_is_nbr_dup(guido))
		ft_error();
}

void	ft_split_strnbr(t_stack *guido, char **av)
{
	int		i;
	char	**matrix;

	matrix = 0;
	matrix = ft_split(av[1], ' ');
	if (!matrix[0])
		ft_error();
	i = 0;
	while (matrix[i] != 0)
		i++;
	guido->stack_a = (int *)malloc(sizeof(int) * i);
	guido->stack_b = (int *)malloc(sizeof(int) * i);
	guido->size_a = 0;
	guido->size_b = 0;
	ft_fill_stack(guido, matrix);
}
