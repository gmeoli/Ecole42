/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:59:12 by masebast          #+#    #+#             */
/*   Updated: 2022/11/10 16:30:33 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_equal_presence(char *string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		if (string[index] == '=')
			return (1);
		index++;
	}
	return (0);
}

int	ft_modify_var(char *new_couple, char **envp)
{
	int		index;
	char	**couple;

	index = 0;
	couple = ft_split(new_couple, '=');
	while (envp[index])
	{
		if (ft_strncmp(envp[index], couple[0], ft_strlen(couple[0])) == 0)
		{
			ft_memcpy(envp[index], new_couple, ft_strlen(new_couple));
			envp[index][ft_strlen(new_couple)] = '\0';
			ft_free_matrix(couple);
			return (1);
		}
		index++;
	}
	ft_free_matrix(couple);
	return (0);
}

int	ft_append_new_key(char **envp, char *new_key)
{
	int	index;

	index = 0;
	if (ft_check_special(new_key) == 1)
		ft_export_error(new_key);
	while (envp[index])
	{
		if (ft_strncmp(envp[index], new_key, ft_strlen(new_key)) == 0)
			return (1);
		index++;
	}
	envp[index] = ft_strdup(new_key);
	envp[index + 1] = NULL;
	return (0);
}

int	ft_modify_append(char **envp, char **words, int index, int *modified_flag)
{
	int	exit_flag;

	exit_flag = 0;
	while (words[++index])
	{
		*modified_flag = 0;
		if (ft_check_char(words[index]) == 0)
		{
			if (ft_check_equal_presence(words[index]) == 1)
			{
				*modified_flag = ft_modify_var(words[index], envp);
				if (*modified_flag == 0)
					ft_append_new_key(envp, words[index]);
			}
			else
				ft_append_new_key(envp, words[index]);
		}
		else
		{
			ft_export_error(words[index]);
			exit_flag = 1;
		}
	}
	return (exit_flag);
}

int	ft_export(t_command *c_s, char **envp)
{
	int	m_i;
	int	modified_flag;
	int	exit_flag;

	m_i = 0;
	exit_flag = 0;
	if (c_s->word_matrix[1] && ft_strncmp(c_s->word_matrix[1], ">>\0", 3) != 0 \
		&& ft_strncmp(c_s->word_matrix[1], ">\0", 2) != 0 \
		&& ft_strncmp(c_s->word_matrix[1], "<<\0", 3) != 0 \
		&& ft_strncmp(c_s->word_matrix[1], "<\0", 2) != 0)
	{
		exit_flag = ft_modify_append(envp, c_s->word_matrix, 0, &modified_flag);
		if (exit_flag == 0)
			*g_exit_status = 0;
		else
			*g_exit_status = 1;
		return (0);
	}
	else
	{
		*g_exit_status = ft_buble_sort_env(envp);
		return (0);
	}
	*g_exit_status = 1;
	return (1);
}
