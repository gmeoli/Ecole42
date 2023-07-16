/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:02:04 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:29:09 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_check_redirection(char **word_struct)
{
	int	index;

	index = 0;
	while (word_struct[index])
	{
		if (ft_find_quotes(word_struct[index]) == 1)
		{
			index++;
			while (ft_find_quotes(word_struct[index]) != 1)
				index++;
		}
		if (strncmp(word_struct[index], ">>\0", 3) == 0
			|| strncmp(word_struct[index], ">\0", 2) == 0
			|| strncmp(word_struct[index], "<<\0", 3) == 0
			|| strncmp(word_struct[index], "<\0", 2) == 0)
			return (1);
		index++;
	}
	return (0);
}

void	ft_dup_and_close(int *stdin_cpy, int *stdout_cpy)
{
	dup2(*stdin_cpy, 0);
	close(*stdin_cpy);
	close(*stdout_cpy);
}

void	ft_wait_and_free(int *index, t_command *c_s, int *pid)
{
	(*index) = -1;
	while (++(*index) < c_s->total_pipes)
		waitpid(pid[(*index)], 0, 0);
	free(pid);
	free(c_s->command_string);
	ft_free_matrix(c_s->pipe_matrix);
}
