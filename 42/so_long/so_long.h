/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:18:31 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/22 19:26:57 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_images {
	void	*img_wall;
	void	*white_box;
	void	*purple_box;
	void	*king;
	void	*queen;
	void	*img_collect;
}	t_images;

typedef struct s_game {
	char		**matrix;
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	int			c;
	int			p;
	int			e;
	int			move_count;
	int			x_player;
	int			y_player;
	t_images	images;
}	t_game;

int		ft_fill_matrix(char *maps, t_game *guido);
int		ft_height(char *maps);
int		ft_width(char *maps);
void	ft_open_images(t_game *guido);
void	ft_error(char *str);
void	ft_print_struct(t_game *guido);
int		ft_check_map(t_game *guido);
void	ft_free_matrix(t_game *guido);
void	end_game(t_game *guido);
void	ft_move_up(t_game *guido);
void	ft_move_right(t_game *guido);
void	ft_move_left(t_game *guido);
void	ft_move_down(t_game *guido);

#endif
