/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:22:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/10 15:10:32 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data {
	int				n_philosophers;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_philosopher_must_eat;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo {
	int	n_to_eat;
	int	index;
}	t_philo;

// CHECK ARGUMENTS
int		ft_atoi(const char *str);
int		ft_contains_char(char **av);

// UTILITY
void	ft_error(void);

//PHILO

#endif
