/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:40:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/18 14:45:15 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *guido)
{
	free(guido->stack_a);
	free(guido->stack_b);
	free(guido->lis);
}

int	main(int ac, char **av)
{
	t_stack	guido;

	if (ac >= 2 && av[1][0] != '\0')
	{
		if (ac > 2)
			ft_allocs_stack(&guido, ac, av);
		else
			ft_split_strnbr(&guido, av);
		if (ft_order(guido.stack_a, guido.size_a))
		{
			ft_free(&guido);
			exit(0);
		}
		ft_renumber_stack(&guido);
		ft_special_condition(&guido);
		ft_lis(&guido);
		ft_push_chunk(&guido);
		ft_algorithm(&guido);
		ft_free(&guido);
	}
	else
		ft_error();
}
