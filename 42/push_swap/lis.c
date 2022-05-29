/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:44:11 by gmeoli            #+#    #+#             */
/*   Updated: 2022/05/29 16:30:35 by gmeoli           ###   ########.fr       */
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

int	*ft_two_case(int *m_backup, int *j, int num)
{
	int	i;
	int	*array;

	array = (int *)malloc(sizeof(int) * *j + 1);
	i = 0;
	while (i < *j)
	{
		array[i] = m_backup[i];
		i++;
	}
	array[i] = num;
	(*j)++;
	return (array);
}

void	ft_three_case(int **m_backup, int j, int num)
{
	int	x;
	int	y;

	x = 0;
	while (x < j)
	{
		if (num < m_backup[x][x])
			break ;
		x++;
	}
	y = 0;
	while (y < x)
	{
		m_backup[x][y] = m_backup[x - 1][y];
		y++;
	}
	m_backup[x][y] = num;
}

void	ft_lis(t_stack *guido)
{
	int	**m_backup;
	int	i;
	int	size_m;
	int	index_min;

	m_backup = ft_init_matrix(guido);
	index_min = ft_index_min(guido);
	i = index_min + 1;
	if (i == guido->size_a)
		i = 0;
	size_m = 1;
	while (guido->stack_a[i] != 1)
	{
		if (guido->stack_a[i] > m_backup[size_m - 1][size_m - 1])
			m_backup[size_m - 1] = ft_two_case(m_backup[size_m - 1], &size_m, \
				guido->stack_a[i]);
		if (guido->stack_a[i] < m_backup[size_m - 1][size_m - 1])
			ft_three_case(m_backup, size_m, guido->stack_a[i]);
		i++;
		if (i == guido->size_a)
			i = 0;
	}
	guido->lis = ft_ardup(m_backup[size_m - 1], size_m);
	guido->size_lis = size_m;
	ft_free_matrix(size_m, m_backup);
}
