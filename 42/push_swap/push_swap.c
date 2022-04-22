/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:40:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/22 22:05:16 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (i < guido.size_a)
	{
		printf("%d	", guido.stack_a[i]);
		i++;
	}
	ft_ra(&guido, true);
	printf("\n");
	i = 0;
	while (i < guido.size_a)
	{
		printf("%d	", guido.stack_a[i]);
		i++;
	}
	// printf("\n");
	// i = 0;
	// while (i < guido.size_b)
	// {
	// 	printf("%d	", guido.stack_b[i]);
	// 	i++;
	// }
	free(guido.stack_a);
	free(guido.stack_b);
}
