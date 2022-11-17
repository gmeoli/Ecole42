/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:01:41 by gmeoli            #+#    #+#             */
/*   Updated: 2022/11/10 16:32:07 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_create_envp_copy(char **envp)
{
	int		i;
	char	**result;

	i = 0;
	while (envp[i])
		i++;
	result = malloc(sizeof(char *) * i + 1);
	i = -1;
	while (envp[++i] != NULL)
		result[i] = ft_strdup(envp[i]);
	result[i] = NULL;
	return (result);
}

char	*ft_getenv_copy(char *key, char **envp_copy)
{
	int		index;
	char	**couple;
	char	*result;

	index = 0;
	couple = NULL;
	while (envp_copy[index])
	{
		if (ft_strncmp(key, envp_copy[index], ft_strlen(key)) == 0)
		{
			couple = ft_split(ft_strdup(envp_copy[index]), '=');
			break ;
		}
		index++;
	}
	result = couple[1];
	free(couple);
	return (result);
}

void	ft_init_struct(t_command *command_struct, char **envp)
{
	char	*value;

	value = ft_itoa(ft_atoi(getenv("SHLVL")) + 1);
	command_struct->current_shell_level = ft_strjoin("SHLVL=", value);
	free(value);
	ft_modify_var(command_struct->current_shell_level, envp);
	command_struct->envp_copy = ft_create_envp_copy(envp);
	command_struct->write_fd = 1;
	command_struct->pipes[0] = 0;
	command_struct->pipes[1] = 1;
	command_struct->total_pipes = 0;
	g_exit_status = malloc(sizeof(int) * 1);
}
