/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:59:23 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/28 19:36:02 by gmeoli           ###   ########.fr       */
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
	while (x < guido->height)
	{
		if (x % 2 == 0)
			guido->images.current_empty = guido->images.white_box;
		else if (x % 2 != 0)
			guido->images.current_empty = guido->images.purple_box;
		y = 0;
		while (y < guido->width)
		{
			if (guido->matrix[x][y] == '0')
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.current_empty, y * 64, x * 64);
			if (guido->matrix[x][y] == '1')
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.img_wall, y * 64, x * 64);
			if (guido->matrix[x][y] == 'C')
			{
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.current_empty, y * 64, x * 64);
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.img_collect, y * 64, x * 64);
			}
			if (guido->matrix[x][y] == 'E')
			{
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.current_empty, y * 64, x * 64);
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.queen, y * 64, x * 64);
			}
			if (guido->matrix[x][y] == 'P')
			{
				printf("x: %d y: %d\n", guido->x_player, guido->y_player);
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.current_empty, guido->y_player * 64, guido->x_player * 64);
				mlx_put_image_to_window(guido->mlx, guido->win, guido->images.king, \
					guido->y_player * 64, guido->x_player * 64);
			}
			if (guido->images.current_empty == guido->images.white_box)
				guido->images.current_empty = guido->images.purple_box;
			else if (guido->images.current_empty == guido->images.purple_box)
				guido->images.current_empty = guido->images.white_box;
			y++;
		}
		x++;
		mlx_string_put(guido->mlx, guido->win, guido->width, \
			guido->height, 0, moves);
	}	
	free(moves);
}
