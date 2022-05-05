/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:37:22 by gmeoli            #+#    #+#             */
/*   Updated: 2022/05/05 17:09:53 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	ft_putstr_fd("-> Error <-\n", 1);
	exit(1);
}

void	ft_final_word(int my_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(my_pid, SIGUSR1);
		i++;
		usleep(100);
	}
}

void	ft_send_string(char *str, int my_pid)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 8;
		while (bit--)
		{
			if (((str[i] >> bit) & 1) == 0)
			{
				if (kill(my_pid, SIGUSR1) == -1)
					ft_error();
			}
			else if (kill(my_pid, SIGUSR2) == -1)
				ft_error();
			usleep(100);
		}
		i++;
	}
	ft_final_word(my_pid);
}

void	ft_ping(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_putstr_fd("Message received!\n", 1);
		exit (0);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	my_pid;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= '0' && av[1][i] <= '9')
				i++;
			else
				ft_error();
		}
		my_pid = ft_atoi(av[1]);
		signal(SIGUSR2, ft_ping);
		ft_send_string(av[2], my_pid);
		while (1)
			;
		return (1);
	}
	ft_putstr_fd("-> Error <-\n", 1);
	ft_putstr_fd("-> Usage: ./client server_PID string <-\n", 1);
	return (0);
}
