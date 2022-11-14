/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renumber_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:09:40 by gmeoli            #+#    #+#             */
/*   Updated: 2022/05/10 13:10:58 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_backup(t_stack *guido, int *backup)
{
	int	i;

	backup = (int *)malloc(sizeof(int) * guido->size_a);
	i = 0;
	while (i < guido->size_a)
	{
		backup[i] = guido->stack_a[i];
		i++;
	}
	return (backup);
}

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
			{
				guido->stack_a[i] = j + 1;
				i++;
				j = -1;
			}
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

	backup = 0;
	backup = ft_backup(guido, backup);
	i = 0;
	while (i < guido->size_a)
	{
		j = i + 1;
		while (j < guido->size_a)
		{
			if (backup[i] > backup[j])
			{
				swap = backup[i];
				backup[i] = backup[j];
				backup[j] = swap;
			}
			j++;
		}
		i++;
	}
	ft_renumber_stack2(guido, backup);
	free(backup);
}
