/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:54:58 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/21 16:35:13 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(void)
{
	printf("Error\n");
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
