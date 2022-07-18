/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:19:56 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/18 20:38:07 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_kill_all(t_data *guido)
{
	int	i;

	i = 0;
	sem_wait(guido->finish);
	while (i < guido->n)
	{
		kill(guido->meoli[i].pid, SIGTERM);
		i++;
	}
}

void	ft_take_forks(t_philo *meoli)
{
	sem_wait(meoli->guido->fork);
	ft_print_msg(meoli, meoli->id, "has taken a fork\n");
	sem_wait(meoli->guido->fork);
	ft_print_msg(meoli, meoli->id, "has taken a fork\n");
}

void	*ft_monitoring(void *meoli)
{
	t_philo		*ph;
	long long	tmp;

	ph = meoli;
	tmp = 0;
	while (TRUE)
	{
		tmp = ft_get_time() - ph->guido->start - ph->last_meal;
		if (tmp > ph->guido->t_death)
		{
			ft_print_msg(ph, ph->id, "died\n");
			exit(0);
		}
	}
	return (NULL);
}

void	*ft_meal(t_philo *meoli)
{
	t_data	*guido;

	guido = meoli->guido;
	meoli->last_meal = ft_get_time() - meoli->guido->start;
	// pthread_create(&meoli->thread, NULL, ft_monitoring, &meoli);
	if (meoli->id % 2 == 0)
		ft_my_sleep(meoli->guido->t_eat);
	while (TRUE)
	{
		ft_take_forks(meoli);
		meoli->last_meal = ft_get_time() - meoli->guido->start;
		ft_print_msg(meoli, meoli->id, "is eating\n");
		ft_my_sleep(meoli->guido->t_eat);
		// sem_post(meoli->guido->fork);
		// sem_post(meoli->guido->fork);
		ft_print_msg(meoli, meoli->id, "is sleeping\n");
		ft_my_sleep(meoli->guido->t_sleep);
		ft_print_msg(meoli, meoli->id, "is thinking\n");
	}
	return (NULL);
}

void	ft_fork(t_data *guido)
{
	int	i;

	i = 0;
	guido->start = ft_get_time();
	while (i < guido->n)
	{
		guido->meoli[i].pid = fork();
		if (guido->meoli[i].pid == 0)
		{
			// pthread_create(&guido->meoli[i].thread, NULL, ft_monitoring, \
			// 	&guido->meoli[i]);
			ft_meal(&guido->meoli[i]);
		}
		i++;
	}
	// sem_wait(guido->end);
	ft_kill_all(guido);
	// waitpid(-1, NULL, 0);
}
