/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:26:41 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/14 20:17:24 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_print_args(int *len, char c, va_list args);
void	ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
int		ft_hexa_min(unsigned int x);
int		ft_hexa_maiu(unsigned int x);
int		ft_pointer(unsigned long int x);
int		ft_decimal(int x);
int		ft_unsint(unsigned int x);

#endif
