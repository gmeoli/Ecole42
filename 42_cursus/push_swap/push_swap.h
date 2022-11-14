/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:32:57 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/18 13:17:53 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_best {
	int	moves;
	int	ma;
	int	mb;
	int	na;
	int	nb;
	int	dir_a;
	int	dir_b;
}	t_best;

typedef struct s_stack {
	int	*stack_a;
	int	*stack_b;
	int	*lis;
	int	size_a;
	int	size_b;
	int	size_lis;
}	t_stack;

// INIZIALIZZAZIONE STRUTTURA 
void	ft_allocs_stack(t_stack *guido, int ac, char **av);
void	ft_fill_stack(t_stack *guido, char **av);

// OPERAZIONI
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

// CHECK VARI
int		ft_is_nbr_dup(t_stack *guido);
int		ft_is_nbr_int(long long int nbr);
int		ft_contains_char(char **av);
void	ft_error(void);
void	ft_split_strnbr(t_stack *guido, char **av);

// UTILITY
void	ft_free_char_matrix(char **matrix);
void	ft_free_matrix(int len, int **matrix);
int		ft_index_min(t_stack *guido);
int		*ft_ardup(int *array, int size);

// SPECIAL CONDITION
void	ft_special_condition(t_stack *guido);

// LIS
void	ft_renumber_stack(t_stack *guido);
void	ft_lis(t_stack *guido);
int		**ft_init_matrix(t_stack *guido);
int		*ft_two_case(int *m_backup, int *j, int num);
void	ft_three_case(int **m_backup, int j, int num);

// PUSH_STACK_B
void	ft_push_chunk(t_stack *guido);

// PUSH_SWAP
void	ft_algorithm(t_stack *guido);
void	ft_algorithm_2(t_stack *guido);

// BONUS
int		ft_order(int *ar, int size);

#endif
