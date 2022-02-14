/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:37:22 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/14 19:52:42 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "ERRORE DI CONNESSIONE", 22);
}

signal(SIGUSR1, my_handler);

