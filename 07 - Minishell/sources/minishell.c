/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:12:49 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:31:19 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_recognize_command(t_command *c_s, int p_i, char **envp)
{
	if (c_s->word_matrix[0] == NULL)
		return (0);
	if (ft_strcmp("echo", c_s->word_matrix[0]) == 0)
		return (ft_echo(c_s, p_i));
	else if (ft_strcmp("cd", c_s->word_matrix[0]) == 0)
		return (ft_cd(c_s));
	else if (ft_strcmp("pwd", c_s->word_matrix[0]) == 0)
		return (ft_pwd());
	else if (ft_strcmp("export", c_s->word_matrix[0]) == 0)
		return (ft_export(c_s, envp));
	else if (ft_strcmp("unset", c_s->word_matrix[0]) == 0)
		return (ft_unset(c_s, envp));
	else if (ft_strcmp("env", c_s->word_matrix[0]) == 0)
		return (ft_env(c_s, envp));
	else if (ft_strcmp("exit", c_s->word_matrix[0]) == 0)
	{
		ft_exit(c_s);
		return (0);
	}
	else
		ft_other_commands(c_s, envp);
	return (0);
}

char	*ft_create_temp(char *command, char *result)
{
	int		index;
	int		res_index;
	char	quote;

	index = -1;
	res_index = 0;
	while (command[++index])
	{
		if (command[index] == '"' || command[index] == '\'')
		{
			quote = command[index];
			while (command[++index] != quote)
				result[res_index++] = command[index];
		}
		else
			result[res_index++] = command[index];
	}
	result[res_index] = '\0';
	return (result);
}

void	ft_remove_quotes(char *command)
{
	char	*result;

	if (ft_check_quote(command) == 1)
	{
		result = malloc(sizeof(char) * ft_strlen(command) + 1);
		result = ft_create_temp(command, result);
		free(command);
		command = ft_strdup(result);
		free(result);
		return ;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_command	command_struct;

	av = NULL;
	if (ac == 1)
	{
		ft_init_struct(&command_struct, envp);
		ft_ctrl_c(envp);
		*g_exit_status = 0;
		while (TRUE)
		{
			ft_manage_signals();
			ft_execute_cycle(&command_struct, command_struct.envp_copy);
		}
	}
	else
		ft_error();
	return (FALSE);
}
