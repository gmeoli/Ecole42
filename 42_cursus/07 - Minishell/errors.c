/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:28:51 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:17:06 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(void)
{
	printf("error\n");
	exit(0);
}

void	ft_command_not_found(char *str)
{
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 20);
	*g_exit_status = 127;
}

void	ft_arg_not_found(char *str)
{
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory\n", 28);
	*g_exit_status = 1;
}

void	ft_syntax_error(char c)
{
	write(2, "minishell: syntax error near unexpected token `", 47);
	write(2, &c, 1);
	write(2, "'\n", 2);
	*g_exit_status = 258;
}

void	ft_unexpected_token(void)
{
	write(2, "minishell: syntax error near unexpected token `newline'\n", 56);
	*g_exit_status = 258;
}
