/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:46:29 by gmeoli            #+#    #+#             */
/*   Updated: 2022/11/17 20:31:21 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_matrix(char **matrix)
{
	int	index;

	index = 0;
	while (matrix[index++])
		printf("%s\n", matrix[index]);
}

int	ft_count_pipes(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 1;
	while (str[index])
	{
		if (str[index] == '\'')
		{
			index++;
			while (str[index] != '\'')
				index++;
		}
		if (str[index] == '\"')
		{
			index++;
			while (str[index] != '\"')
				index++;
		}
		if (str[index] == '|')
			count++;
		index++;
	}
	return (count);
}

void	ft_free_matrix(char **m)
{
	int	i;

	i = 0;
	if (m[0])
	{
		while (m[i])
		{
			free(m[i]);
			i++;
		}
		free(m);
	}
}

int	ft_pipe_total(char *input)
{
	int	pipe_total;
	int	index;

	pipe_total = 0;
	index = 0;
	while (input[index])
	{
		if (input[index] == '"')
		{
			while (input[index] != '"')
				index++;
		}
		else if (input[index] == '\'')
		{
			while (input[index] != '\'')
				index++;
		}
		else if (input[index] == '|')
			pipe_total++;
		index++;
	}
	return (pipe_total);
}

void	ft_exit_on_signal(void)
{
	int	exit_status_copy;

	exit_status_copy = *g_exit_status;
	printf("exit\n");
	free(g_exit_status);
	exit(exit_status_copy);
}
