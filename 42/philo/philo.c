/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:23:07 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/10 12:37:48 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_arguments(t_data *guido, char **av, int ac)
{
	if (ft_contains_char(av) == 1)
		ft_error();
	guido->n_philosophers = ft_atoi(av[1]);
	guido->t_die = ft_atoi(av[2]);
	guido->t_eat = ft_atoi(av[3]);
	guido->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		guido->n_philosopher_must_eat = ft_atoi(av[5]);
}

int	main(int ac, char **av)
{
	t_data	guido;
	t_philo	meoli;

	if (ac == 5 || ac == 6)
		ft_arguments(&guido, av, ac);
	else
		ft_error();
}
