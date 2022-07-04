/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:53:46 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/04 16:19:58 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_death(t_philo *ph)
{
	pthread_mutex_lock(&ph->guido->mutex_death);
	ph->guido->death = 0;
	pthread_mutex_unlock(&ph->guido->mutex_death);
}

void	ft_starving(t_philo *ph)
{
	pthread_mutex_lock(&ph->guido->philo_time);
	ph->last_meal = ft_get_time() - ph->guido->start;
	pthread_mutex_unlock(&ph->guido->philo_time);
}

int	ft_check_mutex(int flag, t_philo *ph)
{
	int	tmp;

	tmp = 0;
	if (flag == 0)
	{
		pthread_mutex_lock(&ph->guido->mutex_death);
		tmp = ph->guido->death;
		pthread_mutex_unlock(&ph->guido->mutex_death);
	}
	else if (flag == 1)
	{
		pthread_mutex_lock(&ph->guido->mutex_must_eat);
		tmp = ph->end;
		pthread_mutex_unlock(&ph->guido->mutex_must_eat);
	}
	return (tmp);
}

void	ft_monitoring(void *philo)
{
	t_philo	*ph;
	int		tmp;
	int		i;
	int		check;

	tmp = 0;
	i = 0;
	check = 0;
	ph = philo;
	while (TRUE)
	{
		if (ft_finish(ph, tmp, i, check) == TRUE)
			break ;
	}
}

void	ft_routine(t_philo *ph)
{
	ft_my_sleep(ph->guido->t_eat);
	pthread_mutex_unlock(ph->right);
	pthread_mutex_unlock(ph->left);
	if (ft_check_mutex(0, ph))
		ft_print_msg(ph, ph->id, "is sleeping\n");
	ft_my_sleep(ph->guido->t_sleep);
	if (ft_check_mutex(0, ph))
		ft_print_msg(ph, ph->id, "is thinking\n");
}
