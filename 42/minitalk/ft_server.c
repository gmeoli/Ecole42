/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:37:37 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/16 19:50:04 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	ft_print_str(int sig, siginfo_t *info, void *context)
{
	char	c;
	char	d;
	int		i;
	
	(void)context;
	i = 0;
	d = 0b10000000;
	c = 0;
	if (sig == SIGUSR1)
		c |= d;
	if (++uchar == 8)
	ft_putchar_fd(c, 1);
		uchar = 0;
		c = 0;
	else
		c <<= 1;
	d >>= 1;
}

int	main(void)
{
	pid_t				process_id;
	struct	sigaction	sig;

	process_id = getpid();
	ft_putstr_fd("The server PID: > ", 1);
	ft_putnbr_fd(process_id, 1);
	ft_putstr_fd(" <\n", 1);
	sig.sa_sigaction = &ft_print_str;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (1);
}
