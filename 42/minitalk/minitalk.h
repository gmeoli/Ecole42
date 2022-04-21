/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:30:02 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/05 16:00:06 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_minitalk {
	unsigned char	c;
	int				i;
}	t_minitalk;

void	ft_print_str(int sig, siginfo_t *info, void *context);
void	ft_send_string(char *str, int my_pid);

#endif
