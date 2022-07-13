/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:23:07 by gmeoli            #+#    #+#             */
/*   Updated: 2022/07/13 16:49:57 by gmeoli           ###   ########.fr       */
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
		guido->meoli[i].end = 0;
		guido->meoli[i].guido = guido;
		i++;
	}
}

sem_t	*ft_init_sem(sem_t *sem, char *str, long long n)
{
	sem_t	*ret;

	if (sem_open(str, O_CREAT | O_EXCL, n) == SEM_FAILED)
	{
		sem_unlink(str);
		sem_close(sem);
		ret = sem_open(str, O_CREAT | O_EXCL, n);
	}
	else
		ret = sem_open(str, O_CREAT | O_EXCL, n);
	return (ret);
}

int	ft_init_data(t_data *guido, char **av, int ac)
{
	if (ft_contains_char(av) == TRUE)
		return (TRUE);
	guido->n = ft_atoi(av[1]);
	guido->t_death = ft_atoi(av[2]);
	guido->t_eat = ft_atoi(av[3]);
	guido->t_sleep = ft_atoi(av[4]);
	guido->forks = ft_init_sem(guido->forks, "/forks", guido->n);
	guido->finish = ft_init_sem(guido->finish, "/finish", 0);
	guido->pid = malloc(sizeof(pid_t) * guido->n);
	if (ac == 6)
	{
		guido->n_philosopher_must_eat = ft_atoi(av[5]);
		if (ft_limits(guido->n_philosopher_must_eat) == TRUE)
			return (TRUE);
	}
	guido->death = 1;
	if (ft_limits(guido->n) == TRUE || ft_limits(guido->t_death) == TRUE \
			|| ft_limits(guido->t_eat) == TRUE || ft_limits(guido->t_sleep) \
			== TRUE)
		return (TRUE);
	guido->meoli = (t_philo *)malloc(sizeof(t_philo) * guido->n);
	if (guido->meoli == NULL)
		return (TRUE);
	return (FALSE);
}

int	main(int ac, char **av)
{
	t_data	guido;

	if (ac == 5 || ac == 6)
	{
		if (ft_init_data(&guido, av, ac) == TRUE)
			ft_error();
		ft_init_philo(&guido);
		ft_fork(&guido);
		free(guido.meoli);
	}
	else
		ft_error();
}
