/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:14:18 by gmeoli            #+#    #+#             */
/*   Updated: 2022/12/09 17:47:44 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strleng(char *file)
{
	int	len;

	len = 0;
	if (!file)
		return (0);
	while (file[len] != '\0')
		len++;
	return (len);
}

void	*ft_callocg(size_t count, size_t size)
{
	size_t	i;
	void	*res;
	char	*tmp;

	i = 0;
	res = (void *) malloc (count * size);
	tmp = (char *)res;
	if (!res)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (res);
}

int	ft_strchrg(const char *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
		return (-1);
	while (s[len] != '\0')
		len++;
	while (i < len + 1)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substrg(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		tmp_start;
	int		i;

	tmp_start = (int)start;
	if (!s)
		return (NULL);
	if ((int)start > (int)ft_strleng((char *)s))
		return (NULL);
	substr = (char *) malloc (len + 1);
	substr[len] = '\0';
	if (!substr)
		return (0);
	i = 0;
	while (start < (tmp_start + len))
	{
		substr[i] = s[(int)start];
		start++;
		i++;
	}
	return (substr);
}

char	*ft_strjoing(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strleng(s1);
	len += ft_strleng(s2);
	str = ft_callocg((len + 1), sizeof(char));
	if (!str)
		return (str);
	while (s1[i] != 0)
	{
		str[i] = (char)s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		str[i] = (char)s2[j];
		i++;
		j++;
	}
	free(s1);
	return (str);
}
