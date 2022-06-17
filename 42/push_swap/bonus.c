/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:36:28 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/17 20:00:39 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_order(int *ar, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (ar[i] > ar[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_execute(t_stack *guido, char *terminal)
{
	if (ft_strncmp(terminal, "sa\n", 3) == 0)
		ft_sa(guido, FALSE);
	else if (ft_strncmp(terminal, "sb\n", 3) == 0)
		ft_sb(guido, FALSE);
	else if (ft_strncmp(terminal, "ss\n", 3) == 0)
		ft_ss(guido, FALSE);
	else if (ft_strncmp(terminal, "pa\n", 3) == 0)
		ft_pa(guido, FALSE);
	else if (ft_strncmp(terminal, "pb\n", 3) == 0)
		ft_pb(guido, FALSE);
	else if (ft_strncmp(terminal, "sb\n", 3) == 0)
		ft_sb(guido, FALSE);
	else if (ft_strncmp(terminal, "ra\n", 3) == 0)
		ft_ra(guido, FALSE);
	else if (ft_strncmp(terminal, "rb\n", 3) == 0)
		ft_rb(guido, FALSE);
	else if (ft_strncmp(terminal, "rr\n", 3) == 0)
		ft_rr(guido, FALSE);
	else if (ft_strncmp(terminal, "rra\n", 4) == 0)
		ft_rra(guido, FALSE);
	else if (ft_strncmp(terminal, "rrb\n", 4) == 0)
		ft_rrb(guido, FALSE);
	else if (ft_strncmp(terminal, "rrr\n", 4) == 0)
		ft_rrr(guido, FALSE);
}

void	ft_checker(t_stack *guido)
{
	char	*str;

	while (TRUE)
	{
		str = get_next_line(0);
		if (str == NULL)
		{
			free(str);
			break ;
		}
		ft_execute(guido, str);
		free(str);
	}
}

int	main(int ac, char **av)
{
	t_stack	guido;

	if (ac >= 2)
	{
		if (ac > 2)
			ft_allocs_stack(&guido, ac, av);
		else
			ft_split_strnbr(&guido, av);
		ft_checker(&guido);
		if (ft_order(guido.stack_a, guido.size_a) == TRUE)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free(guido.stack_a);
		free(guido.stack_b);
	}
	else
		ft_error();
}
