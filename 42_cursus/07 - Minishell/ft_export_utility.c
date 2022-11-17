/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:40:00 by masebast          #+#    #+#             */
/*   Updated: 2022/11/10 15:20:30 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_error(char *identifier)
{
	write(2, "minishell: export: '", 20);
	write(2, identifier, ft_strlen(identifier));
	write(2, "': not a valild identifier\n", 27);
	*g_exit_status = 1;
}

char	**ft_create_envp2(char **envp)
{
	int		index;
	char	**envp2;

	index = 0;
	while (envp[index])
		index++;
	envp2 = malloc(sizeof(char *) * index + 1);
	envp2[index] = NULL;
	if (!envp2)
		return (NULL);
	index = -1;
	while (envp[++index])
		envp2[index] = ft_strdup(envp[index]);
	return (envp2);
}

void	ft_print_envp2(char **envp2)
{
	int		i;
	char	**couple;

	i = 0;
	while (envp2[i])
	{
		if (ft_check_equal_presence(envp2[i]) == 0)
			printf("declare -x %s\n", envp2[i]);
		else
		{
			couple = ft_split(envp2[i], '=');
			if (couple[1] == NULL)
				printf("declare -x %s=\"\"\n", couple[0]);
			else
				printf("declare -x %s=\"%s\"\n", couple[0], couple[1]);
			ft_free_matrix(couple);
		}
		i++;
	}
}

int	ft_check_char(char *str)
{
	if ((str[0] >= 65 && str[0] <= 90) || (str[0] == 95) || \
		(str[0] >= 97 && str[0] <= 122))
		return (0);
	return (1);
}

int	ft_buble_sort_env(char **envp)
{
	int		i;
	int		j;
	char	*tmp;
	char	**envp2;

	i = -1;
	tmp = 0;
	envp2 = ft_create_envp2(envp);
	while (envp2[++i])
	{
		j = i;
		while (envp2[++j])
		{
			if (ft_strcmp(envp2[i], envp2[j]) > 0)
			{
				tmp = envp2[i];
				envp2[i] = envp2[j];
				envp2[j] = tmp;
			}
		}
	}
	ft_print_envp2(envp2);
	ft_free_matrix(envp2);
	return (0);
}
