/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:19:56 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/19 17:56:20 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_kill_all(t_data *guido)
{
	int	i;

	i = 0;
	while (i < guido->n)
	{
		kill(guido->meoli[i].pid, SIGTERM);
		i++;
	}
	sem_close(guido->fork);
	sem_unlink("/forks");
	sem_close(guido->print);
	sem_unlink("/message");
	sem_close(guido->end);
	sem_unlink("/dead");
	sem_close(guido->finish);
	sem_unlink("/must_eat");
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
	t_philo	*ph;
	int		tmp;

	ph = meoli;
	while (TRUE)
	{
		tmp = ft_get_time() - ph->guido->start;
		if (tmp - ph->last_meal > ph->guido->t_death)
		{
			ft_print_msg(ph, ph->id, "died\n");
			// ft_kill_all(ph->guido);
			// exit(0);
		}
	}
	return (NULL);
}

void	*ft_meal(void *meoli)
{
	t_philo	*ph;

	ph = meoli;
	ph->last_meal = ft_get_time() - ph->guido->start;
	pthread_create(&ph->thread, NULL, ft_monitoring, ph);
	if (ph->id % 2 == 0)
		ft_my_sleep(ph->guido->t_eat);
	while (TRUE)
	{
		ft_take_forks(ph);
		ph->last_meal = ft_get_time() - ph->guido->start;
		ft_print_msg(ph, ph->id, "is eating\n");
		ph->n_to_eat++;
		ph->last_meal = ft_get_time() - ph->guido->start;
		ft_my_sleep(ph->guido->t_eat);
		sem_post(ph->guido->fork);
		sem_post(ph->guido->fork);
		ft_print_msg(ph, ph->id, "is sleeping\n");
		ft_my_sleep(ph->guido->t_sleep);
		ft_print_msg(ph, ph->id, "is thinking\n");
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
			ft_meal(&guido->meoli[i]);
		i++;
	}
	sem_wait(guido->end);
	ft_kill_all(guido);
	// waitpid(-1, NULL, 0);
}
