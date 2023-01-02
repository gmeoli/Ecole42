/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:13:03 by gmeoli            #+#    #+#             */
/*   Updated: 2022/12/10 21:18:30 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_check_char(t_map *map)
{
	int	i;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (map->matrix[y][i] != '0' && \
				map->matrix[y][i] != '1' && \
				map->matrix[y][i] != 'C' && \
				map->matrix[y][i] != 'E' && \
				map->matrix[y][i] != 'P')
			{
				ft_error("--> Invalid map <--");
				end_game(map);
				return (0);
			}
		}
	}
	return (1);
}

int	ft_check_perimeter(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->matrix[y][x] != '1' && \
				((x == 0 || x == map->width - 1) || \
				(y == 0 || y == map->height - 1)))
			{
				ft_error("--> Invalid map <--");
				end_game(map);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_uieeeesy(t_map *map, int x, int y)
{
	if (map->matrix[y][x] == 'C')
		map->c++;
	else if (map->matrix[y][x] == 'E')
		map->e++;
	else if (map->matrix[y][x] == 'P')
	{
		map->x_player = x;
		map->y_player = y;
		map->p++;
	}
}

int	ft_check_inside(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < map->height - 1)
	{
		x = 0;
		while (x++ < map->width - 1)
			ft_uieeeesy(map, x, y);
	}
	if (map->c == 0 || map->e == 0 || map->p == 0 || map->p > 1)
	{
		ft_error("--> Invalid map <--");
		end_game(map);
		return (0);
	}
	return (1);
}

int	ft_check_map(t_map *map)
{
	if (ft_check_char(map) == 0)
		return (0);
	else if (ft_check_perimeter(map) == 0)
		return (0);
	else if (ft_check_inside(map) == 0)
		return (0);
	return (1);
}
