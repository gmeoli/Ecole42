/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:25:06 by ebondi            #+#    #+#             */
/*   Updated: 2022/12/11 19:57:41 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_init_struct(t_data *data, char *argv)
{
	t_map	map;

	data->mlx = mlx_init();
	data->win = NULL;
	map.height = 0;
	map.width = 0;
	map.matrix = ft_fill_matrix(&map, argv[1]);
	map.pov = 0;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2 && !check_name(argv[1]))
	{
		ft_init_struct(&data, argv[1]);
		get_map(argv[1], &data);
		// // check_map(&data.map);
		data.win = mlx_new_window(data.mlx, data.map.width * 64, \
			data.map.height * 64, "Play your game!");
	}
	else
		return (ft_error("Invalid arguments\n"));
	return (0);
}
