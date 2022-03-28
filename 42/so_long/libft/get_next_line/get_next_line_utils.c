/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:07:15 by mabasset          #+#    #+#             */
/*   Updated: 2022/02/14 11:14:37 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	free (s2);
	return (i);
}

void	ft_strcpy2(char *save, char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] != '\0')
	{
		save[j] = str[i + j];
		j++;
	}
	str[i] = '\0';
	save[j] = '\0';
}

int	ft_findchr(const char *s, char c)
{
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			break ;
		s++;
	}
	if (*s != c)
		return (0);
	return (1);
}

char	*ft_save(char *str)
{
	char	*save;
	int		i;
	int		j;

	i = 0;
	if (ft_findchr(str, '\n') == 0)
		return (NULL);
	while (str[i] != '\n')
		i++;
	i += 1;
	j = i;
	while (str[j] != '\0')
		j++;
	if (j == i)
		return (NULL);
	save = (char *) malloc (sizeof(char) * (j + 1));
	if (save == NULL)
		return (NULL);
	ft_strcpy2(save, str, i);
	return (save);
}
