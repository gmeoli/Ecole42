/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:59:23 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/29 16:43:25 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(t_game *guido)
{
	int		x;
	int		y;
	char	*moves;

	x = 0;
	guido->images.current_empty = guido->images.purple_box;
	moves = ft_itoa(guido->move_count);
	while (y < guido->height)
	{
		if (y % 2 == 0)
			guido->images.current_empty = guido->images.white_box;
		else
			guido->images.current_empty = guido->images.purple_box;
		x = 0;
		while (x < guido->width)
		{
			mlx_put_image_to_window(guido->mlx, guido->win, guido->images.current_empty, x * 64, y * 64);
			if (guido->matrix[y][x] == '0')
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.current_empty, x * 64, y * 64);
			if (guido->matrix[y][x] == '1')
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.img_wall, x * 64, y * 64);
			if (guido->matrix[y][x] == 'C')
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.img_collect, x * 64, y * 64);
			if (guido->matrix[y][x] == 'E')
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.queen, x * 64, y * 64);
			if (guido->images.current_empty == guido->images.white_box)
				guido->images.current_empty = guido->images.purple_box;
			else if (guido->images.current_empty == guido->images.purple_box)
				guido->images.current_empty = guido->images.white_box;
			x++;
		}
		y++;
		mlx_string_put(guido->mlx, guido->win, guido->width, guido->height, 0, moves);
	}
	mlx_put_image_to_window(guido->mlx, guido->win, guido->images.king, \
	guido->x_player * 64, guido->y_player * 64);
	free(moves);
}
