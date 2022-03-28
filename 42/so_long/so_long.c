/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:18:29 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/28 19:49:23 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_hooks(int key, t_game *guido)
{
	if (key == 53)
		end_game(guido);
	if (key == 13)
		ft_move_up(guido);
	else if (key == 0)
		ft_move_left(guido);
	else if (key == 2)
		ft_move_right(guido);
	else if (key == 1)
		ft_move_down(guido);
	ft_printf("MOVES --> %d", guido->move_count);
	ft_print_map(guido);
	return (0);
}

int	ft_exit(char *str)
{
	ft_putstr_fd(str, 0);
	exit (0);
}

int	main(int ac, char **av)
{
	t_game	guido;

	if (ac == 2)
	{
		guido = ft_allocs_struct();
		ft_fill_matrix(av[1], &guido);
		ft_print_struct(&guido);
		ft_check_map(&guido);
		guido.mlx = mlx_init();
		ft_open_images(&guido);
		guido.win = mlx_new_window(guido.mlx, guido.width * 64, \
			guido.height * 64, "Play your game !");
		ft_print_map(&guido);
		mlx_key_hook(guido.win, ft_hooks, &guido);
		mlx_hook(guido.win, 17, 0, ft_exit, 0);  
		// mlx_do_key_autorepeaton(guido.mlx);
		mlx_loop(guido.mlx);
	}
	write(1, "ERROR! --> Invalid number of arguments <-- \n", 45);
}
