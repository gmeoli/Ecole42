/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:23:07 by gmeoli            #+#    #+#             */
/*   Updated: 2022/06/09 18:08:24 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_arguments(t_philo *guido, char **av)
{
	if (ft_contains_char(&av[0]))
		ft_error();
	if (!ft_is_nbr_int(ft_atoi(av[0])))                    /* RISOLVERE ASSEGNAZIONE DOPO ATOI & FINIRE LA FUNZIONE */
		ft_error();
	guido->t_die = ft_atoi(av[1]);
	guido->t_eat = ft_atoi(av[2]);
	guido->t_sleep = ft_atoi(av[3]);
	guido->n_philosopher_must_eat = ft_atoi(av[4]);
}

int	main(int ac, char **av)
{
	t_philo	guido;

	if (ac == 2)
		ft_arguments(&guido, av + 1);
	// if (ac == 5)

	// else if (ac == 6)

	else
	 	ft_error();
}
