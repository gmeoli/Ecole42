/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:22:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/11 17:19:17 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data {
	int				n;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_philosopher_must_eat;
	long long		time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	finish;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	message;
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
