/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:06:02 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:17:16 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_empty_pipe(char *command, int *index)
{
	while (command[(*index)] == ' ' || command[(*index)] == '|')
	{
		if (command[(*index)] == '|')
		{
			ft_syntax_error(command[(*index)]);
			return (1);
		}
		(*index)++;
	}
	return (0);
}

void	ft_jump_quotes(char *command, int *index, char quote)
{
	(*index)++;
	while (command[(*index)] != quote && command[(*index)])
		(*index)++;
	if (command[(*index) + 1])
		(*index)++;
}

int	ft_trigger_syntax(char *command, int *index, int *flag)
{
	while (command[(*index)])
	{
		if (command[(*index)] == '|')
		{
			ft_syntax_error(command[(*index)]);
			return (1);
		}
		else if (command[(*index)] == ' ')
			(*index)++;
		else if (command[(*index)] != ' ' || command[(*index)] != '|')
		{
			(*flag) = 0;
			break ;
		}
	}
	return (0);
}

int	ft_check_command(char *command, int *index, int *flag)
{
	while (command[(*index)])
	{
		if (command[(*index)] == '\'' || command[(*index)] == '"')
			ft_jump_quotes(command, index, command[(*index)]);
		if (command[(*index)] == '|')
		{
			*flag = 1;
			(*index)++;
			if (command[(*index)] == '\0')
				break ;
			else if (ft_trigger_syntax(command, index, flag) == 1)
				return (1);
		}
		if (command[(*index)] != '\0')
			(*index)++;
	}
	return (0);
}

int	ft_check_syntax(char *command)
{
	int	index;
	int	flag;

	index = 0;
	flag = 0;
	if (ft_check_empty_pipe(command, &index) == 1)
		return (1);
	index = 0;
	if (ft_check_command(command, &index, &flag) == 1)
		return (1);
	if (flag == 1 && (command[index - 1] == '|' || command[index - 1] == ' '))
		return (2);
	return (0);
}
