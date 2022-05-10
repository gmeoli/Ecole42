/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:45:51 by gmeoli            #+#    #+#             */
/*   Updated: 2022/05/10 17:00:36 by gmeoli           ###   ########.fr       */
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
