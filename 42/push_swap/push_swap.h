/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:32:57 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/13 18:20:02 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack {
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stack;

void	ft_allocs_struct(t_stack *guido);
void	ft_sa(t_stack *guido);
void	ft_sb(t_stack *guido);
void	ft_ss(t_stack *guido);
void	ft_pa(t_stack *guido);
void	ft_pb(t_stack *guido);
void	ft_ra(t_stack *guido);
void	ft_fill_stack(t_stack *guido, char **av);

#endif