/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:54:58 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/13 17:53:58 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(void)
{
	printf("Error\n");
	exit(0);
}

long long	ft_get_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}

// void	ft_init_philo(t_data *guido)
// {
// }

void	ft_init(t_data *guido, char **av, int ac)
{
	t_philo	*meoli;

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
	guido->time = ft_get_time();     /* CREARE FUNZIONE PER TEMPO GIIUSTO */
	pthread_mutex_init(&guido->death, NULL);
	pthread_mutex_init(&guido->finish, NULL);
	pthread_mutex_init(&guido->is_eating, NULL);
	pthread_mutex_init(&guido->message, NULL);
	guido->forks = malloc(sizeof(pthread_mutex_t) * guido->n);
	meoli = malloc(sizeof(t_philo) * guido->n);
	guido->meoli = meoli;
	// ft_init_philo(guido);
}
