/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:45:51 by gmeoli            #+#    #+#             */
/*   Updated: 2022/05/11 17:34:21 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**ft_init_matrix(t_stack *guido)
{
	int	**matrix;

	matrix = (int **)malloc(sizeof(int *) * guido->size_a);
	matrix[0] = (int *)malloc(sizeof(int) * 1);
	matrix[0][0] = 1;
	return (matrix);
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

int	*ft_extend_matrix(int *m_backup, int *j, int num)
{
	int	i;
	int	*array;

	array = (int *)malloc(sizeof(int) * j + 1); //VERIFICARE -> *j <-
	i = 0;
	while (i < j) //VERIFICARE -> *j <-
	{
		array[i] = m_backup[i];
		i++;
	}
	array[i] = num;
	(*j)++;
	return (array);
}
