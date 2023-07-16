/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:42:45 by mabasset          #+#    #+#             */
/*   Updated: 2022/02/21 18:31:43 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char const *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		size;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL)
		size = ft_strlen(s2);
	else
		size = ft_strlen(s1) + ft_strlen(s2);
	if (size == 0)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (s1 != NULL)
		i += ft_strcpy(str, s1);
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*str;
	static char	*save;
	int			bytes;

	str = save;
	bytes = 1;
	if (fd < 0 || fd > 256)
		return (NULL);
	buffer = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	while (ft_findchr(str, '\n') == 0 && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		if (bytes < BUFFER_SIZE)
			bytes = 0;
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	save = ft_save(str);
	return (str);
}

/*#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd;

	fd = open("asd.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}*/
