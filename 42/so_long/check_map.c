/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:44:11 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/22 18:51:56 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_char(t_game *guido)
{
	int	x;
	int	y;

	x = 0;
	while (x < guido->height)
	{
		y = 0;
		while (y < guido->width)
		{
			if (guido->matrix[x][y] != '0' && \
				guido->matrix[x][y] != '1' && \
				guido->matrix[x][y] != 'C' && \
				guido->matrix[x][y] != 'E' && \
				guido->matrix[x][y] != 'P' && \
				guido->matrix[x][y] != 'M')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_check_perimeter(t_game *guido)
{
	int	x;
	int	y;

	x = 0;
	while (x < guido->height)
	{
		y = 0;
		while (y < guido->width)
		{
			if (guido->matrix[x][y] != '1' && \
				((x == 0 || x == guido->height - 1) || \
				(y == 0 || y == guido->width - 1)))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_check_inside(t_game *guido)
{
	int	x;
	int	y;

	guido->c = 0;
	guido->e = 0;
	guido->p = 0;
	x = 0;
	while (x++ < guido->height - 1)
	{
		y = 0;
		while (y++ < guido->width - 1)
		{
			if (guido->matrix[x][y] == 'C')
				guido->c++;
			else if (guido->matrix[x][y] == 'E')
				guido->e++;
			else if (guido->matrix[x][y] == 'P')
			{
				guido->x_player = x;
				guido->y_player = y;				
				guido->p++;
			}
		}
	}
	if (guido->c == 0 || guido->e == 0 || guido->p == 0)
		return (0);
	return (1);
}

int	ft_check_map(t_game *guido)
{
	if (ft_check_char(guido) == 0)
		return (0);
	else if (ft_check_perimeter(guido) == 0)
		return (0);
	else if (ft_check_inside(guido) == 0)
		return (0);
	return (1);
}
