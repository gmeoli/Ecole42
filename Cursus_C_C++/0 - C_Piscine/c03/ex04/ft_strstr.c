/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:44:55 by gmeoli            #+#    #+#             */
/*   Updated: 2021/12/08 22:16:17 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = ft_strlen(to_find);
	if (a == 0)
		return (str);
	while (str[i] != '\0')
	{
		while (str[i] != to_find[j] && str[i] != '\0')
			i++;
		while (str[i] == to_find[j] && str[i] != '\0')
		{
			i++;
			j++;
		}
		if (j == a)
			return (str + i - j);
		else
			j = 0;
	}
	return (0);
}
