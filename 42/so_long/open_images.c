/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:01:08 by gmeoli            #+#    #+#             */
/*   Updated: 2022/04/04 18:13:11 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_images(t_game *guido)
{
	guido->images.img_width = 64;
	guido->images.img_height = 64;
	guido->images.img_collect = mlx_xpm_file_to_image \
		(guido->mlx, "img/Collectible.xpm", &guido->images.img_width, \
			&guido->images.img_height);
	guido->images.img_wall = mlx_xpm_file_to_image \
		(guido->mlx, "img/Wall.xpm", &guido->images.img_width, \
			&guido->images.img_height);
	guido->images.king = mlx_xpm_file_to_image \
		(guido->mlx, "img/King.xpm", &guido->images.img_width, \
			&guido->images.img_height);
	guido->images.purple_box = mlx_xpm_file_to_image \
		(guido->mlx, "img/Purple_box.xpm", &guido->images.img_width, \
			&guido->images.img_height);
	guido->images.queen = mlx_xpm_file_to_image \
		(guido->mlx, "img/Queen.xpm", &guido->images.img_width, \
			&guido->images.img_height);
	guido->images.white_box = mlx_xpm_file_to_image \
		(guido->mlx, "img/White_box.xpm", &guido->images.img_width, \
			&guido->images.img_height);
}
