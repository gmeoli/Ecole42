/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:46:44 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/28 18:24:15 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_fork(t_philo *ph)
{
	pthread_mutex_lock(ph->right);
	if (ft_check_mutex(0, ph))
		ft_print_msg(ph, ph->id, "has taken a fork\n");
	if (ph->guido->n == 1)
		return (TRUE);
	pthread_mutex_lock(ph->left);
	if (ft_check_mutex(0, ph))
		ft_print_msg(ph, ph->id, "has taken a fork\n");
	return (FALSE);
}

void	*ft_meal(void *meoli)
{
	t_philo	*ph;

	ph = meoli;
	ft_starving(ph);
	if (ph->id % 2 == 0)
		ft_my_sleep(ph->guido->t_eat);
	while (ft_check_mutex(0, ph))
	{
		if (ft_take_fork(ph))
			break ;
		if (ft_check_mutex(0, ph))
			ft_print_msg(ph, ph->id, "is eating\n");
		ph->n_to_eat++;
		if (ph->n_to_eat == ph->guido->n_philosopher_must_eat)
		{
			pthread_mutex_lock(&ph->guido->mutex_must_eat);
			ph->end = 1;
			pthread_mutex_unlock(&ph->guido->mutex_must_eat);
		}
		ft_starving(ph);
		ft_routine(ph);
	}
	return (NULL);
}

int	ft_finish(t_philo *meoli, int tmp, int i, int check)
{
	while (i < meoli->guido->n)
	{
		pthread_mutex_lock(&meoli->guido->philo_time);
		tmp = ft_get_time() - meoli->guido->start - meoli[i].last_meal;
		pthread_mutex_unlock(&meoli->guido->philo_time);
		if (tmp > meoli->guido->t_death)
		{
			ft_check_death(meoli);
			usleep(2000);
			ft_print_msg(&meoli[i], meoli[i].id, "died\n");
			return (TRUE);
		}
		if (ft_check_mutex(1, &meoli[i]))
			check++;
		i++;
	}
	if (check == meoli->guido->n)
	{
		ft_check_death(meoli);
		return (TRUE);
	}
	return (FALSE);
}

void	ft_exit(t_data *guido)
{
	int	i;

	i = 0;
	while (i < guido->n)
	{
		pthread_mutex_destroy(&guido->forks[i]);
		pthread_mutex_destroy(&guido->philo_time);
		i++;
	}
	pthread_mutex_destroy(&guido->lock);
	pthread_mutex_destroy(&guido->mutex_death);
	pthread_mutex_destroy(&guido->mutex_must_eat);
}

void	ft_thread(t_data *guido)
{
	int	i;

	i = 0;
	guido->start = ft_get_time();
	while (i < guido->n)
	{
		pthread_create(&guido->meoli[i].thread, NULL, ft_meal, \
			&guido->meoli[i]);
		i++;
	}
	i = 0;
	ft_monitoring(guido);
	while (i < guido->n)
	{
		pthread_join(guido->meoli[i].thread, NULL);
		i++;
	}
	ft_exit(guido);
}
