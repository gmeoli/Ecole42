/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:22:55 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:31:32 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_jump_c_f(char *command, int *i, int *flag)
{
	while (command[*i] == ' ')
		(*i)++;
	*i += 4;
	while (command[*i] == ' '
		|| command[*i] == '-')
	{
		if (command[*i] == '-'
			&& command[*i + 1] == 'n'
			&& (command[*i + 2] == ' '
				|| command[*i + 2] == '\0'))
		{
			*i += 3;
			*flag = 1;
		}
		else if (command[*i] == '-'
			&& command[*i] != 'n')
			break ;
		else
			(*i)++;
	}
}

void	ft_print_echo(t_command *c_s, char *command, int *i)
{
	while (command[*i])
	{
		while (command[*i] == ' '
			&& command[*i + 1] == ' ')
			(*i)++;
		if (command[*i] == '\'')
			*i += ft_print_single(command + *i, c_s->write_fd);
		else if (command[*i] == '"')
			*i += ft_print_double(command + *i, c_s->write_fd, c_s->envp_copy);
		else if (command[*i] == '$' && command[*i + 1] != ' ' \
			&& command[*i + 1])
			*i += (ft_print_doll(command + *i, c_s->write_fd, c_s->envp_copy));
		else if (command[*i] == '>'
			|| command[*i] == '<')
			break ;
		else
		{
			if (&command[*i] != '\0')
				write(c_s->write_fd, &command[*i], 1);
			(*i)++;
		}
	}
}

int	ft_echo(t_command *c_s, int p_i)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	c_s->pipe_matrix[p_i] = ft_adjust_pipe(c_s->pipe_matrix[p_i]);
	if (ft_check_quote(c_s->pipe_matrix[p_i]) == 1)
	{
		ft_jump_c_f(c_s->pipe_matrix[p_i], &i, &flag);
		ft_print_echo(c_s, c_s->pipe_matrix[p_i], &i);
		if (flag == 0)
			write(c_s->write_fd, "\n", 1);
		*g_exit_status = 0;
		return (0);
	}
	else
	{
		write(2, "error: close your quotes\n", 25);
		return (1);
	}
}
