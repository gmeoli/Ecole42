/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:44:40 by masebast          #+#    #+#             */
/*   Updated: 2022/11/05 15:19:08 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_heredoc(char *pipe)
{
	char	*updated;
	int		index;

	index = 0;
	while (pipe[index] != '<')
		index++;
	updated = malloc(sizeof(char) * index + 1);
	index = -1;
	while (pipe[++index] != '<')
		updated[index] = pipe[index];
	updated[index] = '\0';
	free(pipe);
	return (updated);
}

void	ft_cycle_here(char *interrupter, int pipes[2])
{
	char	*sub_read;

	while (1)
	{
		sub_read = readline("> ");
		if (sub_read && ft_strcmp(sub_read, interrupter) == 0)
		{
			write(pipes[1], "\0", 1);
			free(sub_read);
			break ;
		}
		else
		{
			if (sub_read == NULL)
				break ;
			write(pipes[1], sub_read, ft_strlen(sub_read));
			write(pipes[1], "\n", 1);
			free(sub_read);
		}
	}
}

void	ft_heredoc(t_command *c_s, int p_i, char **envp, int *i)
{
	char	*interrupter;
	int		pipes[2];
	int		stdincpy;

	stdincpy = dup(0);
	if (ft_check_token(c_s, i) == 1)
		return ;
	else
	{
		interrupter = strdup(c_s->word_matrix[(*i) + 1]);
		c_s->pipe_matrix[p_i] = ft_remove_heredoc(c_s->pipe_matrix[p_i]);
		ft_free_matrix(c_s->word_matrix);
		c_s->word_matrix = ft_split(c_s->pipe_matrix[p_i], ' ');
		pipe(pipes);
		ft_cycle_here(interrupter, pipes);
		close(pipes[1]);
		dup2(pipes[0], STDIN_FILENO);
		if (i != 0)
			ft_recognize_command(c_s, p_i, envp);
		dup2(stdincpy, STDIN_FILENO);
		close(pipes[0]);
		free(interrupter);
		return ;
	}
}

int	ft_input_redirect(t_command *c_s, int *fd, int *i)
{
	*fd = open(c_s->word_matrix[(*i) + 1], O_RDWR, 0644);
	if (*fd == -1)
	{
		ft_arg_not_found(c_s->word_matrix[(*i) + 1]);
		*g_exit_status = 1;
		return (1);
	}
	else
	{
		*g_exit_status = 0;
		return (2);
	}
}

void	ft_redirect_input(t_command *c_s, int p_i, char **envp, int *index)
{
	int	fd;
	int	incpy;

	incpy = dup(0);
	if (ft_strcmp(c_s->word_matrix[(*index)], "<<") == 0)
		ft_heredoc(c_s, p_i, envp, index);
	else if (ft_strcmp(c_s->word_matrix[(*index)], "<") == 0)
	{
		if (c_s->word_matrix[(*index) + 1] == NULL)
		{
			ft_unexpected_token();
			return ;
		}
		else if (ft_input_redirect(c_s, &fd, index) != 1 \
			|| ft_input_redirect(c_s, &fd, index) != 2)
		{
			c_s->word_matrix = ft_decrease_word_matrix(c_s->word_matrix);
			dup2(fd, STDIN_FILENO);
			ft_recognize_command(c_s, p_i, envp);
			dup2(incpy, STDIN_FILENO);
			close(fd);
		}
	}
}
