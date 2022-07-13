/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:19:56 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/13 17:14:02 by gmeoli           ###   ########.fr       */
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
	ft_print_msg(meoli, meoli->id, "is taking a fork\n");
	sem_wait(meoli->guido->forks);
	ft_print_msg(meoli, meoli->id, "is taking a fork\n");
}

void	ft_meal(t_philo *meoli)
{
	if (meoli->id % 2 == 0)
		ft_my_sleep(meoli->guido->t_eat);
	while (TRUE)
	{
		ft_take_forks(meoli);
		meoli->last_meal = ft_get_time();
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
