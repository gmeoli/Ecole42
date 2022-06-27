/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:46:44 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/27 19:07:40 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			ft_print_msg(&meoli, meoli[i].id, "died");
			return (TRUE);
		}
		///////////////////////////////////////////////////
		i++;
	}
}

void	ft_monitoring(t_data *guido)
{
	int	tmp;
	int	i;
	int	check;

	tmp = 0;
	i = 0;
	check = 0;
	while (TRUE)
	{
		if (ft_finish(guido->meoli, tmp, i, check))
			break ;
	}
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
}
