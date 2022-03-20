/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:18:29 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/20 20:38:01 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	guido;

	if (ac == 2)
	{
		printf("%d", ft_fill_matrix(av[1], &guido));
		//printf("%c", guido.matrix);	
	}
	write(0, "ERROR!\nNumber of invalid arguments\n", 36);
	exit (0);
}

/* MAIN FOR TEST FUNCTION */

// int	main()
// {
// 	void	*mlx;
// 	void	*win;
// 	int		x;
// 	int		y;
// 	int		c;
// 	int		d;
// 	// int		e;
// 	// int		f;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "!!!!");
// 	x = 50;
// 	while (x < 150)
// 	{
// 		y = 50;
// 		while (y < 150)
// 		{
// 			mlx_pixel_put(mlx, win, x, y, 0x8F00FF);
// 			y++;
// 		}
// 		x++;
// 	}
// 	c = 300;
// 	while (c < 450)
// 	{
// 		d = 50;
// 		while (d < 150)
// 		{
// 			mlx_pixel_put(mlx, win, c, d, 0x8F00FF);
// 			d++;
// 		}
// 		c++;
// 	}
// 	mlx_loop(mlx);
// 	// sleep(5000);
// 	// exit(0);
// }