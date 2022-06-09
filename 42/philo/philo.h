/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:22:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/09 17:54:49 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo {
	int	n_philosophers;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_philosopher_must_eat;
}	t_philo;

// CHECK ARGUMENTS
int		ft_atoi(const char *str);
int		ft_contains_char(char **av);
int		ft_is_nbr_int(int nbr);

// UTILITY
void	ft_error(void);

//PHILO

#endif
