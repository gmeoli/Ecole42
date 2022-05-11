/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:44:11 by gmeoli            #+#    #+#             */
/*   Updated: 2022/05/11 17:09:13 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lis(t_stack *guido)
{
	int	**m_backup;
	int	i;
	int	j;
	int	index_min;

	m_backup = ft_init_matrix(guido);
	index_min = ft_index_min(guido);
	i = index_min + 1;
	if (i == guido->size_a)
		i = 0;
	j = 1;
	while (guido->stack_a[i] != 1)
	{
		if (guido->stack_a[i] > m_backup[j - 1][j - 1])
			m_backup[j - 1] = ft_extend_matrix(m_backup[j - 1], &j, \
				guido->stack_a[i]);
		i++;
		if (i == guido->size_a)
			i = 0;
	}
	ft_free_matrix(guido->size_a, m_backup);
}
