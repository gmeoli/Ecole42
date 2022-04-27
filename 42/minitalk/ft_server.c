/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:37:37 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/27 12:06:29 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_str(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 1;

	(void)context;
	if (sig == SIGUSR1)
		c |= 0;
	else
		c |= 1;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		if (c == 0)
			kill(info->si_pid, SIGUSR2);
		i = 1;
		c = 0;
		return ;
	}
	i++;
	c <<= 1;
}

int	main(void)
{
	pid_t				process_id;
	struct sigaction	sig;

	process_id = getpid();
	ft_putstr_fd("The server PID: > ", 1);
	ft_putnbr_fd(process_id, 1);
	ft_putstr_fd(" <\n", 1);
	sig.sa_sigaction = ft_print_str;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
