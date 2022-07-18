/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:54:58 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/18 20:00:58 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		return (FALSE);
	return (TRUE);
}

void	ft_my_sleep(long long time)
{
	long long	i;

	i = ft_get_time();
	while (time > ft_get_time() - i)
		usleep(50);
}

void	ft_print_msg(t_philo *meoli, int id, char *str)
{
	sem_wait(meoli->guido->print);
	printf("%lld %d %s", ft_get_time() - meoli->guido->start, id, str);
	sem_post(meoli->guido->print);
}
