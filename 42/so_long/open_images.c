/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:01:08 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/21 17:36:54 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_images(t_game *guido)
{
	guido->images.img_collect = mlx_xpm_file_to_image \
		(guido->mlx, "img/Collectible.xpm", &guido->width, &guido->height);
	guido->images.img_wall = mlx_xpm_file_to_image \
		(guido->mlx, "img/Wall.xpm", &guido->width, &guido->height);
	guido->images.king = mlx_xpm_file_to_image \
		(guido->mlx, "img/King.xpm", &guido->width, &guido->height);
	guido->images.purple_box = mlx_xpm_file_to_image \
		(guido->mlx, "img/Purple_box.xpm", &guido->width, &guido->height);
	guido->images.queen = mlx_xpm_file_to_image \
		(guido->mlx, "img/Queen.xpm", &guido->width, &guido->height);
	guido->images.white_box = mlx_xpm_file_to_image \
		(guido->mlx, "img/White_box.xpm", &guido->width, &guido->height);
}
