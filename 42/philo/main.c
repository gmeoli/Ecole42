/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:23:07 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/21 16:55:48 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(t_data *guido)
{
	int	i;

	i = 0;
	while (i < guido->n)
	{
		
		i++;
	}
}

int	ft_init_mutex(t_data *guido)
{
	int	i;

	guido->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * guido->n);
	if (guido->forks == NULL)
		return (TRUE);
	i = 0;
	while (i < guido->n)
	{
		pthread_mutex_init(&guido->forks[i], NULL);
		i++;
	}
	return (FALSE);
}

int	ft_init_data(t_data *guido, char **av, int ac)
{
	if (ft_contains_char(av) == TRUE)
		return (TRUE);
	guido->n = ft_atoi(av[1]);
	guido->t_death = ft_atoi(av[2]);
	guido->t_eat = ft_atoi(av[3]);
	guido->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		guido->n_philosopher_must_eat = ft_atoi(av[5]);
	guido->death = 1;
	if (ft_limits(guido->n) == TRUE || ft_limits(guido->t_death) == TRUE \
			|| ft_limits(guido->t_eat) == TRUE || ft_limits(guido->t_sleep) \
			== TRUE || ft_limits(guido->n_philosopher_must_eat) == TRUE)
		return (TRUE);
	if (ft_init_mutex(guido) == TRUE)
		return (TRUE);
	guido->meoli = (t_philo *)malloc(sizeof(t_philo) * guido->n);
	if (guido->meoli == NULL)
		return (TRUE);
	return (FALSE);
}

int	main(int ac, char **av)
{
	t_data	guido;

	if (ac == 5 || ac == 6)
	{
		if (ft_init_data(&guido, av, ac) == TRUE)
			ft_error();
		ft_init_philo(&guido);
	}
	else
		ft_error();
}
