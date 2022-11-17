/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:44:46 by masebast          #+#    #+#             */
/*   Updated: 2022/11/16 15:22:04 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_open_pipe(t_command *c_s)
{
	char	*swap;
	char	*sub_readline;

	swap = NULL;
	sub_readline = NULL;
	while (ft_check_syntax(c_s->command_string) == 2)
	{
		sub_readline = readline("> ");
		swap = ft_strjoin(c_s->command_string, sub_readline);
		free(c_s->command_string);
		c_s->command_string = ft_strdup(swap);
		free(swap);
		free(sub_readline);
		if (ft_check_syntax(c_s->command_string) == 1)
		{
			free(c_s->command_string);
			return ;
		}
	}
}

void	ft_direction(t_command *c_s, char **envp)
{
	int	i;

	i = -1;
	c_s->word_matrix = ft_split(c_s->pipe_matrix[0], ' ');
	while (c_s->word_matrix[++i])
		ft_remove_quotes(c_s->word_matrix[i]);
	ft_expand_dollar(c_s->word_matrix, c_s);
	if (ft_check_redirection(c_s->word_matrix) == 1)
	{
		ft_redirect(c_s, 0, envp);
		ft_free_matrix(c_s->word_matrix);
		ft_free_matrix(c_s->pipe_matrix);
		free(c_s->command_string);
		return ;
	}
	ft_recognize_command(c_s, 0, envp);
	ft_free_matrix(c_s->word_matrix);
	ft_free_matrix(c_s->pipe_matrix);
	free(c_s->command_string);
}

int	ft_check_spaces_only(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
		if (str[index] != ' ')
			return (0);
	return (1);
}

int	ft_check_command_string(char *string)
{
	if (!string)
		ft_exit_on_signal();
	if (ft_check_spaces_only(string) == 1)
	{
		free(string);
		return (1);
	}
	return (0);
}

void	ft_execute_cycle(t_command *c_s, char **envp)
{
	c_s->command_string = readline("minishell$ ");
	if (ft_check_command_string(c_s->command_string) == 1)
		return ;
	if (c_s->command_string[0] != '\0')
	{
		if (ft_check_quote(c_s->command_string) != 1)
		{
			ft_error_in_history(c_s);
			return ;
		}
		if (ft_check_syntax(c_s->command_string) == 1)
		{
			ft_add_and_free(c_s);
			return ;
		}
		else if (ft_check_syntax(c_s->command_string) == 2)
			ft_open_pipe(c_s);
		ft_history_pipe_matrix(c_s);
		if (c_s->total_pipes > 1)
			ft_manage_pipes(c_s, envp);
		else
			ft_direction(c_s, envp);
	}
	else
		free(c_s->command_string);
}
