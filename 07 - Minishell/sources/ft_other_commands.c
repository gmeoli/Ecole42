/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:29:07 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:29:07 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_execute_sub_process(t_command *c_s, char **envp)
{
	if (execve(c_s->word_matrix[0], c_s->word_matrix, envp) != 0)
	{
		ft_arg_not_found(c_s->word_matrix[0]);
		return (1);
	}
	return (0);
}

void	ft_quit_130(int sig)
{
	if (sig == SIGINT)
		write(1, "^C\n", 3);
	*g_exit_status = 130;
	return ;
}

void	ft_nephew(t_command *c_s, char **mypath, int *index, char **envp)
{
	char	*path;

	path = getenv("PATH");
	path = ft_strjoin(mypath[(*index)], c_s->word_matrix[0]);
	if (access(path, R_OK) == 0)
		*g_exit_status = execve(path, c_s->word_matrix, envp);
	else if (strncmp(c_s->word_matrix[0], "./", 2) == 0)
	{
		*g_exit_status = ft_execute_sub_process(c_s, envp);
		exit(*g_exit_status);
	}
	else
		*g_exit_status = execve(c_s->word_matrix[0], c_s->word_matrix, envp);
	free(path);
}

void	ft_child(t_command *c_s, char **envp)
{
	int		index;
	char	*path;
	char	**mypath;

	path = getenv("PATH");
	mypath = ft_split(path, ':');
	index = -1;
	while (mypath[++index])
		mypath[index] = ft_strjoin(mypath[index], "/");
	index = -1;
	while (mypath[++index])
		ft_nephew(c_s, mypath, &index, envp);
	if (*g_exit_status != 0)
		ft_command_not_found(c_s->word_matrix[0]);
	exit(*g_exit_status);
}

int	ft_other_commands(t_command *command_struct, char **envp)
{
	int		status;
	pid_t	pid;

	status = 0;
	pid = fork();
	if (pid == 0)
		ft_child(command_struct, envp);
	else
	{
		signal(SIGINT, ft_quit_130);
		waitpid(pid, &status, 0);
		if (status != 0 && *g_exit_status != 130)
			*g_exit_status = 127;
	}
	return (1);
}
