/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:23:07 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/21 00:17:36 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_philo(t_data *guido)
{
	int	i;

	i = 0;
	while (i < guido->n)
	{
		guido->meoli[i].id = i + 1;
		guido->meoli[i].n_to_eat = 0;
		guido->meoli[i].guido = guido;
		i++;
	}
}

static sem_t	*ft_init_sem(sem_t *sem, const char *str, unsigned int n)
{
	sem_t	*ret;

	(void)sem;
	ret = sem_open(str, O_CREAT | O_EXCL, 0644, n);
	if (ret != SEM_FAILED)
		return (ret);
	sem_unlink(str);
	return (sem_open(str, O_CREAT, 0644, n));
}

int	ft_init_data(t_data *guido, char **av, int ac)
{
	if (ft_contains_char(av) == FALSE)
		return (FALSE);
	guido->n = ft_atoi(av[1]);
	guido->t_death = ft_atoi(av[2]);
	guido->t_eat = ft_atoi(av[3]);
	guido->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		guido->n_philosopher_must_eat = ft_atoi(av[5]);
		if (ft_limits(guido->n_philosopher_must_eat) == FALSE)
			return (FALSE);
	}
	if (ft_limits(guido->n) == FALSE || ft_limits(guido->t_death) == FALSE \
			|| ft_limits(guido->t_eat) == FALSE || ft_limits(guido->t_sleep) \
			== FALSE)
		return (FALSE);
	guido->fork = ft_init_sem(guido->fork, "/forks", guido->n);
	guido->must_eat = ft_init_sem(guido->must_eat, "/must_eat", 0);
	guido->print = ft_init_sem(guido->print, "/print", 1);
	guido->end = ft_init_sem(guido->end, "/end", 0);
	guido->last_print = ft_init_sem(guido->last_print, "/last", 1);
	guido->meoli = (t_philo *)malloc(sizeof(t_philo) * guido->n);
	if (guido->meoli == NULL)
		return (FALSE);
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_data	guido;

	if (ac == 5 || ac == 6)
	{
		if (ft_init_data(&guido, av, ac) == FALSE)
			ft_error();
		ft_init_philo(&guido);
		ft_fork(&guido);
		free(guido.meoli);
	}
	else
		ft_error();
}
