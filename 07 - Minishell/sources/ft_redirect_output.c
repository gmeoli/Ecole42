/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:44:28 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:30:10 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_append(t_command *c_s, int p_i, char **envp, int *i)
{
	int	fd;

	if (c_s->word_matrix[(*i) + 1] == NULL)
	{
		ft_unexpected_token();
		return ;
	}
	fd = open(c_s->word_matrix[(*i) + 1], O_APPEND | O_CREAT | O_WRONLY, 0644);
	ft_red_exe(c_s, p_i, envp, fd);
}

void	ft_trunc(t_command *c_s, int p_i, char **envp, int *i)
{
	int	fd;

	if (c_s->word_matrix[(*i) + 1] == NULL)
	{
		ft_unexpected_token();
		return ;
	}
	fd = open(c_s->word_matrix[(*i) + 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	ft_red_exe(c_s, p_i, envp, fd);
}

void	ft_redirect_output(t_command *c_s, int p_i, char **envp, int *index)
{
	if (ft_strcmp(c_s->word_matrix[(*index)], ">>") == 0)
		ft_append(c_s, p_i, envp, index);
	else if (ft_strcmp(c_s->word_matrix[(*index)], ">") == 0)
		ft_trunc(c_s, p_i, envp, index);
}
