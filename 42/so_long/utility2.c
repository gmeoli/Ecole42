/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:20:35 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/05 09:49:09 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == 'b' && str[i + 2] == 'e' \
				&& str[i + 3] == 'r' && str[i + 4] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_error_line(int fd, int width)
{
	char	*str;
	int		i;

	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		free(str);
		if (i != width)
			ft_error("--> Invalid map <--");
		str = get_next_line(fd);
	}
	free(str);
}
