/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:09:40 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/23 17:43:02 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_renumber_stack2(t_stack *guido, int *backup)
{
	int	i;
	int	j;

	i = 0;
	while (i < guido->size_a)
	{
		j = 0;
		while (j < guido->size_a)
		{
			if (guido->stack_a[i] == backup[j])
				guido->stack_a[i] = j + 1;
			j++;
		}
		i++;
	}
}

void	ft_renumber_stack(t_stack *guido)
{
	int	*backup;
	int	i;
	int	j;
	int	swap;

	backup = (int *)malloc(sizeof(int) * guido->size_a);
	backup = guido->stack_a;
	i = 0;
	while (i < guido->size_a)
	{
		j = i + 1;
		while (j < guido->size_a)
		{
			if (guido->stack_a[i] > guido->stack_a[j])
			{
				swap = guido->stack_a[i];
				guido->stack_a[i] = guido->stack_a[j];
				guido->stack_a[j] = swap;
			}
			j++;
		}
		i++;
	}
	ft_renumber_stack2(guido, backup);
	// free(backup);
}
