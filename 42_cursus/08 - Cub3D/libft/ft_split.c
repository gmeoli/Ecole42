/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarsi <atarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:11:30 by ebondi            #+#    #+#             */
/*   Updated: 2022/10/17 18:57:42 by atarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	dosplit(char **mat, size_t count, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (count > 0)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != 0)
			i++;
		mat[k] = (char *)malloc(sizeof(char) * (i - j + 1));
		if (!mat[k])
			return ;
		ft_strlcpy(mat[k], &s[j], (i - j + 1));
		count--;
		k++;
	}
}

static size_t	count_w(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
			w++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_w(s, c);
	matrix = (char **)malloc(sizeof(char *) * (count + 1));
	if (count == 0)
	{
		matrix[0] = NULL;
		return (matrix);
	}
	if (!matrix)
		return (NULL);
	matrix[count] = NULL;
	dosplit(matrix, count, s, c);
	return (matrix);
}
