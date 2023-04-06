/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:18:08 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:30:57 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ctrl_c(char **envp)
{
	int		n;
	char	*cmd[3];

	cmd[0] = ft_strdup("stty");
	cmd[1] = ft_strdup("-echoctl");
	cmd[2] = NULL;
	n = fork();
	if (!n)
		execve("/bin/stty", cmd, envp);
	waitpid(-1, NULL, 0);
	free(cmd[0]);
	free(cmd[1]);
}

void	sig_new_line(int n)
{
	(void)n;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_manage_signals(void)
{
	signal(SIGINT, sig_new_line);
	signal(SIGQUIT, SIG_IGN);
}
