/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:19:56 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/21 00:18:08 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_kill_all(t_data *guido)
{
	int	i;

	i = 0;
	sem_wait(guido->end);
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
	sem_unlink("/end");
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
			sem_wait(ph->guido->last_print);
			printf("%lld %d died\n", ft_get_time() - ph->guido->start, ph->id);
			sem_post(ph->guido->end);
			exit(0);
		}
	}
	return (NULL);
}

void	*ft_check_must_eat(void *guido)
{
	t_data	*data;
	int		i;

	data = guido;
	i = 0;
	while (i < data->n)
	{
		sem_wait(data->must_eat);
		i++;
	}
	sem_post(data->end);
	return (NULL);
}

void	*ft_meal(void *meoli)
{
	t_philo	*ph;

	ph = meoli;
	ph->last_meal = ft_get_time() - ph->guido->start;
	pthread_create(&ph->thread, NULL, ft_monitoring, ph);
	while (TRUE)
	{
		ft_take_forks(ph);
		ph->last_meal = ft_get_time() - ph->guido->start;
		ft_print_msg(ph, ph->id, "is eating\n");
		ph->n_to_eat++;
		if (ph->n_to_eat == ph->guido->n_philosopher_must_eat)
			sem_post(ph->guido->must_eat);
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
	pthread_create(&guido->eat, NULL, ft_check_must_eat, guido);
	while (i < guido->n)
	{
		guido->meoli[i].pid = fork();
		if (guido->meoli[i].pid == 0)
		{
			ft_meal(&guido->meoli[i]);
			return ;
		}
		i++;
	}
	ft_kill_all(guido);
}
