/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:08:12 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:29:14 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_pwd(void)
{
	char	path[PATH_MAX];
	int		index;

	index = 0;
	if (getcwd(path, sizeof(path)) != NULL)
	{
		while (path[index])
		{
			write(1, &path[index], 1);
			index++;
		}
		write(1, "\n", 1);
		*g_exit_status = 0;
		return (0);
	}
	else
	{
		write(2, "pwd error\n", 10);
		*g_exit_status = 1;
		return (1);
	}
}
