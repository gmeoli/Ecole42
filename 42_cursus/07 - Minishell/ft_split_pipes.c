/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:16:17 by masebast          #+#    #+#             */
/*   Updated: 2022/11/02 17:30:20 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_quotes(const char *s, char quote)
{
	int	index;

	index = 1;
	if (quote != '\'' && quote != '"')
		return (0);
	while (s[index] != quote && s[index])
		index++;
	return (index + 1);
}

char	*malloc_strings_pipes(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '\'' || s[i] == '"')
			i += skip_quotes(&s[i], s[i]);
		else
			i++;
	}
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		ft_quote_control(s, &i, word);
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_split_pipes_cycle(const char *s, int *i, char **tab, char c)
{
	while (*s)
	{
		while (*s && *s == c)
		{
			s += skip_quotes(s, *s);
			s++;
		}
		if (*s && *s != c)
		{
			tab[(*i)] = malloc_strings_pipes(s, c);
			(*i)++;
			while (*s && *s != c)
			{
				if (*s == '\'' || *s == '"')
					s += skip_quotes(s, *s);
				else
					s++;
			}
		}
	}
}

char	**ft_split_pipes(const char *s, char c)
{
	int		words;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	words = count_strings_pipes(s, c);
	if (words == 1)
		c = '\0';
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	ft_split_pipes_cycle(s, &i, tab, c);
	tab[i] = NULL;
	return (tab);
}
