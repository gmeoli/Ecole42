/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:19:56 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/15 17:50:58 by gmeoli           ###   ########.fr       */
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
		kill(guido->pid[i], SIGTERM);
		i++;
	}
}

void	ft_take_forks(t_philo *meoli)
{
	sem_wait(meoli->guido->forks);
	ft_print_msg(meoli, meoli->id, "has taken a fork\n");
	sem_wait(meoli->guido->forks);
	ft_print_msg(meoli, meoli->id, "has taken a fork\n");
}

void	*ft_monitoring(void *meoli)
{
	long long		tmp;
	t_philo	*ph;

	ph = meoli;
	tmp  = 0;
	printf("LAST: %lld\n", ph->last_meal);
	while (TRUE)
	{
		tmp = (ft_get_time() - ph->guido->start) - ph->last_meal;
		// printf("TMP: %lld\n", tmp);
		if (tmp > ph->guido->t_death)
		{
			// ft_print_msg(ph, ph->id, "died\n");
			exit(0);
		}
	}
	return (NULL);
}

void	ft_meal(t_philo *meoli)
{
	pthread_create(&meoli->thread, NULL, ft_monitoring, &meoli);
	if (meoli->id % 2 == 0)
		ft_my_sleep(meoli->guido->t_eat);
	while (TRUE)
	{
		ft_take_forks(meoli);
		meoli->last_meal = ft_get_time() - meoli->guido->start;
		printf("LAST: %lld\t%lld\n", ft_get_time(), meoli->guido->start);
		printf("TOT: %lld\n", meoli->last_meal);
		ft_print_msg(meoli, meoli->id, "is eating\n");
		ft_my_sleep(meoli->guido->t_eat);
		sem_post(meoli->guido->forks);
		sem_post(meoli->guido->forks);
		ft_print_msg(meoli, meoli->id, "is sleeping\n");
		ft_my_sleep(meoli->guido->t_sleep);
		ft_print_msg(meoli, meoli->id, "is thinking\n");
	}
}

void	ft_fork(t_data *guido)
{
	int	i;

	i = 0;
	guido->start = ft_get_time();
	while (i < guido->n)
	{
		guido->pid[i] = fork();
		if (guido->pid[i] == 0)
		{
			ft_meal(&guido->meoli[i]);
			return ;
		}
		i++;
	}
	waitpid(-1, NULL, 0);
	ft_kill_all(guido);
}
