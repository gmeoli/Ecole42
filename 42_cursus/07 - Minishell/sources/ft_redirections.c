/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:45:04 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:30:16 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_jump_redirects(char *updated, int *count, char *pipe, int *index)
{
	char	quote;

	while (pipe[(*index)])
	{
		if (pipe[(*index)] == '\'' || pipe[(*index)] == '"')
		{
			quote = pipe[(*index)];
			updated[(*count)++] = pipe[(*index)++];
			while (pipe[(*index)] != quote)
				updated[(*count)++] = pipe[(*index)++];
			updated[(*count)++] = pipe[(*index)++];
		}
		if (pipe[(*index)] == '>' || pipe[(*index)] == '<')
		{
			(*index)++;
			while (pipe[(*index)] != ' ' && pipe[(*index)])
				(*index)++;
			while (pipe[(*index)] == ' ' && pipe[(*index)])
				(*index)++;
			while (pipe[(*index)] != ' ' && pipe[(*index)])
				(*index)++;
		}
		else
			updated[(*count)++] = pipe[(*index)++];
	}
}

char	*ft_update_pipe_text(char *pipe)
{
	int		index;
	int		count;
	char	*updated;

	updated = malloc(sizeof(char) * ft_strlen(pipe));
	index = 0;
	count = 0;
	ft_jump_redirects(updated, &count, pipe, &index);
	updated[count] = '\0';
	free(pipe);
	return (updated);
}

void	ft_red_exe(t_command *c_s, int p_i, char **envp, int fd)
{
	int	stdoutcpy;

	stdoutcpy = dup(1);
	c_s->pipe_matrix[p_i] = ft_update_pipe_text(c_s->pipe_matrix[p_i]);
	c_s->word_matrix = ft_decrease_word_matrix(c_s->word_matrix);
	close(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	ft_recognize_command(c_s, p_i, envp);
	dup2(stdoutcpy, STDOUT_FILENO);
	close(fd);
}

int	ft_red_hot_chili_pepper(t_command *c_s, int *index, int p_i, char **envp)
{
	if (ft_strcmp(c_s->word_matrix[(*index)], ">>") == 0
		|| ft_strcmp(c_s->word_matrix[(*index)], ">") == 0)
	{
		ft_redirect_output(c_s, p_i, envp, index);
		return (1);
	}
	return (0);
}

void	ft_redirect(t_command *c_s, int p_i, char **envp)
{
	int	index;

	index = 0;
	while (c_s->word_matrix[index])
	{
		if (ft_find_quotes(c_s->word_matrix[index]) == 1)
		{
			index++;
			while (ft_find_quotes(c_s->word_matrix[index]) != 1)
				index++;
		}
		if (ft_red_hot_chili_pepper(c_s, &index, p_i, envp) == 1)
			break ;
		else if (ft_strcmp(c_s->word_matrix[index], "<<") == 0 \
			|| ft_strcmp(c_s->word_matrix[index], "<") == 0)
		{
			ft_redirect_input(c_s, p_i, envp, &index);
			break ;
		}
		if (c_s->word_matrix[index + 1] != NULL)
			index++;
	}
}
