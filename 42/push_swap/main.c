/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:40:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/23 17:15:01 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_array(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d	", array[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	guido;
	int	i;

	i = 0;
	ft_allocs_stack(&guido, ac);
	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2));
	if (ac < 3 && get_word(av[1], ' ') < 2)
		return (ft_putstr_fd("Error\n", 2));
	ft_fill_stack(&guido, &av[1]);
	ft_renumber_stack(&guido);
	free(guido.stack_a);
	free(guido.stack_b);
}
