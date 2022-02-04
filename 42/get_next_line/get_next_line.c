/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:21:46 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 16:48:43 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 50

char	*get_next_line(int fd)
{
	char		*file;
	static char	*save[4096];

	if (fd < 0 || fd > 4096)
		return (NULL);
	file = get_line(fd, save[fd]);
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
		if (count == -1)
			return (NULL);
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

int main()
{
	int 	fd;
	char	*file;

	fd = open("file.txt", O_RDONLY);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	return (1);
}