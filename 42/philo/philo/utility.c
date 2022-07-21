/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:54:58 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/05 16:32:50 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

long long	ft_get_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}

int	ft_limits(long long nb)
{
	if (nb <= 0 || nb > 2147483647)
		return (TRUE);
	return (FALSE);
}

void	ft_print_msg(t_philo *meoli, int id, char *str)
{
	pthread_mutex_lock(&meoli->guido->lock);
	printf("%lld %d %s", ft_get_time() - meoli->guido->start, id, str);
	pthread_mutex_unlock(&meoli->guido->lock);
}

void	ft_my_sleep(long long time)
{
	long long	i;

	i = ft_get_time();
	usleep(time * 1000 - 20000);
	while (ft_get_time() < i + time)
		continue ;
}
