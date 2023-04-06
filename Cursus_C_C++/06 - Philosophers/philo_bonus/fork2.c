/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:18:49 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/21 13:08:56 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_kill_all(t_data *guido)
{
	int	i;

	i = 0;
	sem_wait(guido->end);
	while (i < guido->n)
	{
		kill(guido->meoli[i].pid, SIGTERM);
		i++;
	}
	sem_close(guido->fork);
	sem_unlink("/forks");
	sem_close(guido->print);
	sem_unlink("/message");
	sem_close(guido->end);
	sem_unlink("/end");
}
