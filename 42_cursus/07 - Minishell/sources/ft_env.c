/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:17:10 by gmeoli            #+#    #+#             */
/*   Updated: 2022/11/17 20:28:45 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env(t_command *command_struct, char **envp)
{
	int	index;

	index = 0;
	if (command_struct->word_matrix[1])
	{
		ft_arg_not_found(command_struct->word_matrix[1]);
		return (0);
	}
	while (envp[index])
	{
		if (ft_check_equal_presence(envp[index]) == 1)
			printf("%s\n", envp[index]);
		index++;
	}
	*g_exit_status = 0;
	return (0);
}
