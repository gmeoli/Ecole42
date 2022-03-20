/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:49:04 by gmeoli            #+#    #+#             */
/*   Updated: 2022/03/19 14:45:20 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_width(char *maps)
{
	int		fd;
	char	*result;
	int		width;
	
	result = 0;
	width = 0;
	fd = open(maps, O_RDONLY);
	if (!fd)
		return (0);
	result = get_next_line(fd);
	width = ft_strlen(result) - 1;
	free(result);
	close(fd);
	return (width);
}

int	ft_height(char *maps)
{
	int		fd;
	char	*result;
	int		height;
	
	result = 0;
	height = 0;
	fd = open(maps, O_RDONLY);
	if (!fd)
		return (0);
	result = get_next_line(fd);
	while (result != NULL)
	{
		height++;
		free(result);
		result = get_next_line(fd);
	}
	free(result);
	close(fd);
	return (height);
}

int	ft_fill_matrix(char *maps, t_game *guido)
{
	int	fd;

	guido->width = ft_width(maps);
	guido->height = ft_height(maps);
	guido->matrix = (char **)malloc(sizeof(char *) * guido->height + 1);
	guido->matrix[guido->height] = NULL;	
}