/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:46:44 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/27 17:35:09 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_philo *ph)
{
	int	temp;

	pthread_mutex_lock(&ph->guido->mutex_death);
	temp = ph->guido->death;
	pthread_mutex_unlock(&ph->guido->mutex_death);
	return (temp);
}

int	ft_take_fork(t_philo *ph)
{
	pthread_mutex_lock(ph->right);
	if (ft_check_death(ph))
		ft_print_msg(ph, ph->id, "has taken a fork\n");
	if (ph->guido->n == 1)
		return (FALSE);
	pthread_mutex_lock(ph->left);
	if (ft_check_death(ph))
		ft_print_msg(ph, ph->id, "has taken a fork\n");
	return (TRUE);
}

void	ft_starving(t_philo *ph)
{
	pthread_mutex_lock(&ph->guido->philo_time);
	ph->last_meal = ft_get_time() - ph->guido->start;
	pthread_mutex_unlock(&ph->guido->philo_time);
}

void	*ft_meal(void *meoli)
{
	t_philo	*ph;

	ph = meoli;
	ft_starving(ph);
	while (ft_check_death(ph))
	{
		if (ft_take_fork(ph) == FALSE)
			break ;
	}
	return (NULL);
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
	while (i < guido->n)
	{
		pthread_join(guido->meoli[i].thread, NULL);
		i++;
	}
}
