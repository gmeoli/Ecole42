/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:51:14 by gmeoli            #+#    #+#             */
/*   Updated: 2022/12/11 19:56:45 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**ft_fill_matrix(t_map *map, char *maps)
{
	int		i;
	int		j;
	char	**matrix;

	map->height = ft_height(maps);
	map->width = ft_width(maps);
	i = -1;
	matrix = malloc(sizeof(char *) * map->height + 1);
	while (++i < map->height)
	{
		matrix[i] = malloc(sizeof(char) * map->width + 1);
		j = -1;
		while (++j < map->width)
		{
			matrix[i][j] = maps[i][j];
		}
		matrix[i][j] = '\0';
	}
	matrix[i] = NULL;
	return (matrix);
}
