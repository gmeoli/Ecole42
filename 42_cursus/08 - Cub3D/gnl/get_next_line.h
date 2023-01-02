/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:14:38 by gmeoli            #+#    #+#             */
/*   Updated: 2022/12/09 17:47:13 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strleng(char *file);
char	*get_line(int fd, char *save);
void	*ft_callocg(size_t count, size_t size);
int		ft_strchrg(const char *s, char c);
char	*ft_substrg(char const *s, unsigned int start, size_t len);
char	*ft_strjoing(char *s1, char *s2);
char	*ft_save(char *save, char *file);

#endif
