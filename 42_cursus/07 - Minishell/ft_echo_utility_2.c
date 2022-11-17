/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utility_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:26:53 by gmeoli            #+#    #+#             */
/*   Updated: 2022/11/17 20:17:18 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_single(char *string, int fd)
{
	int	index;

	index = 1;
	while (string[index] != '\'')
	{
		write(fd, &string[index], 1);
		index++;
	}
	index++;
	return (index);
}

int	ft_print_double(char *string, int fd, char **env_copy)
{
	int	index;

	index = 1;
	while (string[index] != '"')
	{
		if (string[index] == '$')
			index += ft_print_doll(string + index, fd, env_copy);
		else
		{
			write(fd, &string[index], 1);
			index++;
		}
	}
	index++;
	return (index);
}

void	ft_print_exit(void)
{
	char	*status;

	status = ft_itoa(*g_exit_status);
	write (1, status, ft_strlen(status));
	free(status);
}

int	ft_check_quote(char *str)
{
	int		index;
	int		flag;
	char	quote;

	index = 0;
	flag = 1;
	while (str[index])
	{
		if (str[index] == '\'' || str[index] == '\"')
		{
			flag *= -1;
			quote = str[index];
			while (str[++index])
			{
				if (str[index] == quote)
				{
					flag *= -1;
					break ;
				}
			}
		}
		index++;
	}
	return (flag);
}
