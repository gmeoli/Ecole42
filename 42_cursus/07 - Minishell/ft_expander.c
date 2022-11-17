/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:21:59 by masebast          #+#    #+#             */
/*   Updated: 2022/11/17 20:17:20 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_return_value(char *key_couple)
{
	char	**couple;
	char	*result;

	couple = ft_split(key_couple, '=');
	if (couple[1])
	{
		result = ft_strdup(couple[1]);
		ft_free_matrix(couple);
		return (result);
	}
	else
	{
		ft_free_matrix(couple);
		return (NULL);
	}
}

char	*ft_env_expander(char *key, char **env_copy)
{
	int	index;

	index = 0;
	if (ft_strcmp(key, "?") == 0)
	{
		free(key);
		return (ft_itoa(*g_exit_status));
	}
	while (env_copy[index])
	{
		if (ft_strncmp(key, env_copy[index], ft_strlen(key)) == 0)
		{
			free (key);
			return (ft_return_value(env_copy[index]));
		}
		index++;
	}
	return (key);
}

char	*ft_return_expanded(char *string, t_command *c_s)
{
	int		index;
	int		var_index;
	char	*may_be_var;

	index = 1;
	var_index = 0;
	may_be_var = malloc(sizeof(char) * ft_strlen(string));
	while (string[index])
		may_be_var[var_index++] = string[index++];
	may_be_var[var_index] = '\0';
	free (string);
	may_be_var = ft_env_expander(may_be_var, c_s->envp_copy);
	return (may_be_var);
}

char	**ft_expand_dollar(char **word_matrix, t_command *c_s)
{
	int	index;

	index = 0;
	while (word_matrix[index])
	{
		if (word_matrix[index][0] == '$')
			word_matrix[index] = ft_return_expanded(word_matrix[index], c_s);
		index++;
	}
	return (word_matrix);
}
