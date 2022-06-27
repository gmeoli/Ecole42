/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:53:46 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/27 18:55:24 by gmeoli           ###   ########.fr       */
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

void	ft_starving(t_philo *ph)
{
	pthread_mutex_lock(&ph->guido->philo_time);
	ph->last_meal = ft_get_time() - ph->guido->start;
	pthread_mutex_unlock(&ph->guido->philo_time);
}
