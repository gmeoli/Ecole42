/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:22:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/20 16:07:23 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philo {
	int				n_to_eat;
	int				id;
	long long		last_meal;
	pid_t			pid;
	pthread_t		thread;
	struct s_data	*guido;
}	t_philo;

typedef struct s_data {
	long long		n;
	long long		t_death;
	long long		t_eat;
	long long		t_sleep;
	long long		n_philosopher_must_eat;
	long long		start;
	pthread_t		eat;
	sem_t			*last_print;
	sem_t			*print;
	sem_t			*fork;
	sem_t			*must_eat;
	sem_t			*end;
	t_philo			*meoli;
}	t_data;

// CHECK ARGUMENTS
int			ft_atoi(const char *str);
int			ft_contains_char(char **av);

// UTILITY
void		ft_error(void);
long long	ft_get_time(void);
int			ft_limits(long long nb);
void		ft_print_msg(t_philo *guido, int id, char *str);
void		ft_my_sleep(long long time);

//PHILO
void		ft_fork(t_data *guido);

#endif
