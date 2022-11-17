/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:21 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:17:25 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_create_freed_copy(char **envp, int index)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	while (envp[i])
		i++;
	result = malloc(sizeof(char *) * i - 1);
	result[i - 1] = NULL;
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (i == index)
		{
			free(envp[index]);
			i++;
		}
		else
			result[j++] = (envp[i++]);
	}
	return (result);
}

char	**ft_find_in_envp(char *key, char **envp)
{
	int	index;

	index = 0;
	while (envp[index])
	{
		if (strncmp(key, envp[index], ft_strlen(key)) == 0)
			return (ft_create_freed_copy(envp, index));
		index++;
	}
	return (envp);
}

int	ft_unset(t_command *command_struct, char **envp)
{
	int		index;
	int		word_index;
	char	**copy;

	word_index = 1;
	if (!command_struct->word_matrix[1])
		return (1);
	while (command_struct->word_matrix[word_index])
	{
		copy = ft_find_in_envp(command_struct->word_matrix[word_index], envp);
		if (copy == envp)
			return (1);
		index = 0;
		while (copy[index++])
		envp[index] = NULL;
		index = 0;
		while (copy[index++])
			envp[index] = copy[index];
		free(copy);
		word_index++;
	}
	return (0);
}
