/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:21:23 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/05 19:24:46 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*file;
	static char	*save[4096];
	size_t		i;

	i = 0;
	if (fd < 0 || fd > 4096)
		return (NULL);
	save[fd] = get_line(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	while (save[fd][i] && save[fd][i] != '\n')
		i++;
	file = ft_substr(save[fd], 0, i + 1);
	save[fd] = ft_save(save[fd], file);
	return (file);
}

char	*get_line(int fd, char *save)
{
	int		count;
	char	*buffer;

	count = 1;
	if (!save)
		save = ft_calloc (1, 1);
	while (count > 0 && ft_strchr(save, '\n') == -1)
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0 || (count == 0 && save[0] == 0))
		{
			free(save);
			free(buffer);
			return (NULL);
		}
		save = ft_strjoin(save, buffer);
		free (buffer);
	}
	return (save);
}

char	*ft_save(char *save, char *file)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (file[i])
		i++;
	if (save[i] == 0)
	{
		free(save);
		return (NULL);
	}
	tmp = ft_substr(save, i, ft_strlen(save) - i);
	free(save);
	save = ft_substr(tmp, 0, ft_strlen(tmp));
	free(tmp);
	return (save);
}
