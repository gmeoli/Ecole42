/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:40:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/21 16:41:45 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	guido;
	int i;

	i = 0;
	ft_allocs_stack(&guido, ac);
	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2));
	if (ac < 3 && get_word(av[1], ' ') < 2)
		return (ft_putstr_fd("Error\n", 2));
	ft_fill_stack(&guido, &av[1]);
	// while (i < guido.size_a)
	// {
	// 	printf("%d	", guido.stack_a[i]);
	// 	i++;
	// }
	// ft_sa(&guido);
	free(guido.stack_a);
	free(guido.stack_b);
}
