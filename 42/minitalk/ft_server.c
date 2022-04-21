/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:37:37 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/06 20:53:37 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_str(int sig, siginfo_t *info, void *context)
{
	t_minitalk	g_stream;

	(void)context;
	g_stream.i = 8;
	g_stream.c |= (sig == SIGUSR2);
	if (g_stream.i++)
	{
		if (!g_stream.c)
		{
			usleep(300);
			kill(info->si_pid, SIGUSR2);
			g_stream.c = 0;
			g_stream.i = 0;
			write(1, "\n", 1);
			return ;
		}
		else
			ft_putchar_fd(g_stream.c, 1);
		g_stream.c = 0;
		g_stream.i = 0;
	}
	g_stream.c <<= 1;
	pause();
}

int	main(void)
{
	pid_t				process_id;
	struct sigaction	sig;
	t_minitalk			g_stream;

	process_id = getpid();
	g_stream.c = 0;
	g_stream.i = 0;
	ft_putstr_fd("The server PID: > ", 1);
	ft_putnbr_fd(process_id, 1);
	ft_putstr_fd(" <\n", 1);
	sig.sa_sigaction = &ft_print_str;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
