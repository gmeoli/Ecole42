/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cycle_utility.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:05:36 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:28:48 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_history_pipe_matrix(t_command *c_s)
{
	add_history(c_s->command_string);
	c_s->total_pipes = ft_count_pipes(c_s->command_string);
	c_s->pipe_matrix = ft_split_pipes(c_s->command_string, '|');
}

void	ft_error_in_history(t_command *c_s)
{
	add_history(c_s->command_string);
	printf("error: close your quotes\n");
	free(c_s->command_string);
}

void	ft_add_and_free(t_command *c_s)
{
	add_history(c_s->command_string);
	free(c_s->command_string);
}
