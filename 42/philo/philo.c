/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:23:07 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/11 17:50:28 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}

void	ft_init(t_data *guido, char **av, int ac)
{
	if (ft_contains_char(av) == 1)
		ft_error();
	guido->n = ft_atoi(av[1]);
	guido->t_die = ft_atoi(av[2]);
	guido->t_eat = ft_atoi(av[3]);
	guido->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		guido->n_philosopher_must_eat = ft_atoi(av[5]);
		if (guido->n_philosopher_must_eat <= 0)
			ft_error();
	}
	guido->time = ft_get_time();
	pthread_mutex_init(&guido->death, NULL);
	pthread_mutex_init(&guido->finish, NULL);
	pthread_mutex_init(&guido->is_eating, NULL);
	pthread_mutex_init(&guido->message, NULL);
	guido->forks = malloc(sizeof(pthread_mutex_t) * guido->n);
}

int	main(int ac, char **av)
{
	t_data	guido;
	// t_philo	meoli;

	if (ac == 5 || ac == 6)
	{
		ft_init(&guido, av, ac);
	}
	else
		ft_error();
}
