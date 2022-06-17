/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:54:32 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/17 17:02:08 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_min(t_stack *guido)
{
	int	i;

	i = 0;
	while (i < guido->size_a)
	{
		if (guido->stack_a[i] == 1)
			break ;
		i++;
	}
	return (i);
}

int	*ft_ardup(int *array, int size)
{
	int	i;
	int	*array2;

	array2 = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		array2[i] = array[i];
		i++;
	}
	return (array2);
}

void	ft_free_matrix(int len, int **matrix)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
