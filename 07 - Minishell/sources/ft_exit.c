/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:29:36 by gmeoli            #+#    #+#             */
/*   Updated: 2022/11/17 20:28:55 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_set_exit_status(char *arg)
{
	int	exit_status;
	int	index;

	index = 0;
	while (arg[index])
	{
		if (ft_isdigit(arg[index]) == 0)
		{
			printf("exit: %s: numeric argument required\n", arg);
			*g_exit_status = 255;
			return ;
		}
		index++;
	}
	exit_status = ft_atoi(arg);
	if (exit_status > 256)
		exit_status %= 256;
	*g_exit_status = exit_status;
}

void	ft_exit(t_command *c_s)
{
	printf("exit\n");
	if (c_s->word_matrix[1])
		ft_set_exit_status(c_s->word_matrix[1]);
	if (c_s->pipe_matrix)
		ft_free_matrix(c_s->pipe_matrix);
	if (c_s->word_matrix)
		ft_free_matrix(c_s->word_matrix);
	if (c_s->command_string)
		free(c_s->command_string);
	exit(*g_exit_status);
}
