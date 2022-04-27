/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:32:57 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/27 17:44:18 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_stack {
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stack;

void	ft_allocs_stack(t_stack *guido, int ac, char **av);
void	ft_sa(t_stack *guido, int can_print);
void	ft_sb(t_stack *guido, int can_print);
void	ft_ss(t_stack *guido, int can_print);
void	ft_pa(t_stack *guido, int can_print);
void	ft_pb(t_stack *guido, int can_print);
void	ft_ra(t_stack *guido, int can_print);
void	ft_rb(t_stack *guido, int can_print);
void	ft_rr(t_stack *guido, int can_print);
void	ft_rra(t_stack *guido, int can_print);
void	ft_rrb(t_stack *guido, int can_print);
void	ft_rrr(t_stack *guido, int can_print);
void	ft_fill_stack(t_stack *guido, char **av);
int		ft_is_nbr_dup(t_stack *guido);
int		ft_is_nbr_int(long long int nbr);
int		ft_contains_char(char **av);
void	ft_error(void);
void	ft_renumber_stack(t_stack *guido);
void	ft_renumber_stack2(t_stack *guido, int *backup);
void	ft_print_array(int *array, int len);
void	ft_split_strnbr(t_stack *guido, char **av);

#endif
