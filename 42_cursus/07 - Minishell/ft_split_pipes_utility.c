/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipes_utility.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:29:08 by masebast          #+#    #+#             */
/*   Updated: 2022/11/02 17:30:15 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_strings_pipes(const char *s, char c)
{
	int		act_pos;
	int		str_count;

	act_pos = 0;
	str_count = 0;
	while (s[act_pos] != '\0')
	{
		if (s[act_pos] == '\'' || s[act_pos] == '"')
			act_pos += skip_quotes(&s[act_pos], s[act_pos]);
		if (s[act_pos] == c)
			str_count++;
		act_pos++;
	}
	str_count++;
	return (str_count);
}

void	ft_quote_control(const char *s, int *i, char *word)
{
	char	quote;

	if (s[(*i)] == '\'' || s[(*i)] == '"')
	{
		quote = s[(*i)];
		word[(*i)] = s[(*i)];
		(*i)++;
		while (s[(*i)] != quote)
		{
			word[(*i)] = s[(*i)];
			(*i)++;
		}
		word[(*i)] = s[(*i)];
	}
	else
		word[(*i)] = s[(*i)];
}
