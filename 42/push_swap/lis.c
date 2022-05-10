/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:44:11 by gmeoli            #+#    #+#             */
/*   Updated: 2022/05/10 18:03:12 by gmeoli           ###   ########.fr       */
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
	ft_free_matrix(guido->size_a, m_backup);
}
