/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:37:22 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/27 16:27:01 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_final_word(int my_pid)
{
	int	i;
/////////////////////////////
//////////////////////////
//////////////////////////
//////////////////////////////
	i = 0;
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
				kill(my_pid, SIGUSR1);
			else
				kill(my_pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	// ft_final_word(my_pid);
}

int	main(int ac, char **av)
{
	int	my_pid;

	if (ac == 3)
	{
		my_pid = ft_atoi(av[1]);
		ft_send_string(av[2], my_pid);
		return (1);
	}
	ft_putstr_fd("--> Error <--\n", 1);
	ft_putstr_fd("--> Usage: ./client server_PID string <--\n", 1);
	return (0);
}
