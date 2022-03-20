/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:37:37 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/18 12:05:01 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_str(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		g_stream.c |= g_stream.d;
	if (!g_stream.d)
	{
		if (!g_stream.c)
			kill(info->si_pid, SIGUSR1);
		else
			ft_putchar_fd(g_stream.c, 1);
		g_stream.c = 0;
		g_stream.d = 0b10000000;
	}
	//c <<= 1;
	g_stream.d >>= 1;
	pause();
}

int	main(void)
{
	pid_t				process_id;
	struct	sigaction	sig;

	process_id = getpid();
	// sigemptyset(&sig.sa_mask);
	ft_putstr_fd("The server PID: > ", 1);
	ft_putnbr_fd(process_id, 1);
	ft_putstr_fd(" <\n", 1);
	sig.sa_sigaction = &ft_print_str;
	g_stream.c = 0;
	g_stream.d = 0b10000000;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (1);
}
