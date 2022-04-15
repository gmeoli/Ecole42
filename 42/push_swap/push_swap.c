/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:40:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/15 11:57:47 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	guido;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2));
	if (ac < 3 && get_word(av[1], ' ') < 2)
		return (ft_putstr_fd("Error\n", 2));
	ft_check_error(&guido, av);	
	
	// if (ac > 2)
	// {
		// guido.stack_a = (int*)malloc(sizeof(int) * ac - 1);
		// guido.stack_b = (int*)malloc(sizeof(int) * ac - 1);
		// guido.size_a = (int)malloc(sizeof(int) * ac - 1);
		// guido.size_b = 0;
		// ft_fill_stack(&guido, &av[1]);
		//ft_sa(&guido);
	// }
}
