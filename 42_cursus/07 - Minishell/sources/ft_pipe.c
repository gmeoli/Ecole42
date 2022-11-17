/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:19:47 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:29:12 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_dup_close_and_free(int pipes[2], char **word_matrix)
{
	dup2(pipes[0], STDIN_FILENO);
	close(pipes[0]);
	close(pipes[1]);
	ft_free_matrix(word_matrix);
}

void	ft_close_son(t_command *c_s, int pipes[2], int index, char **envp)
{
	close(pipes[0]);
	ft_redirect(c_s, index, envp);
	exit(0);
}

void	ft_pipe_split_rm_quotes(int pipes[2], int index, t_command *c_s)
{
	pipe(pipes);
	c_s->word_matrix = ft_split(c_s->pipe_matrix[index], ' ');
	ft_remove_quotes(c_s->word_matrix[0]);
}

void	ft_son(t_command *c_s, int index, char **envp, int pipes[2])
{
	int	stdout_cpy;

	stdout_cpy = dup(1);
	ft_expand_dollar(c_s->word_matrix, c_s);
	if (ft_check_redirection(c_s->word_matrix) == 1)
		ft_close_son(c_s, pipes, index, envp);
	else
	{
		close(pipes[0]);
		if (index == c_s->total_pipes - 1)
			dup2(stdout_cpy, STDOUT_FILENO);
		else
			dup2(pipes[1], STDOUT_FILENO);
		ft_recognize_command(c_s, index, envp);
		exit(0);
	}
}

void	ft_manage_pipes(t_command *c_s, char **envp)
{
	int	index;
	int	pipes[2];
	int	*pid;
	int	stdin_cpy;
	int	stdout_cpy;

	stdin_cpy = dup(0);
	stdout_cpy = dup(1);
	index = -1;
	pid = malloc(sizeof(int) * c_s->total_pipes);
	while (++index < c_s->total_pipes)
	{
		ft_pipe_split_rm_quotes(pipes, index, c_s);
		pid[index] = fork();
		if (pid[index] == 0)
			ft_son(c_s, index, envp, pipes);
		else
			ft_dup_close_and_free(pipes, c_s->word_matrix);
	}
	ft_dup_and_close(&stdin_cpy, &stdout_cpy);
	ft_wait_and_free(&index, c_s, pid);
}
