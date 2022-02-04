/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:26:41 by gmeoli            #+#    #+#             */
/*   Updated: 2022/01/22 23:31:51 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_struct
{
	int minus;
	int	zero;
	int	hash;
	int	space;
	int	plus;
	int width;
	int precision;
}				t_struct;

int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_struct_init(t_struct *params);
int		ft_checkflags(const char *str, t_struct *params);
int		ft_checkidentifier(char c);
void	ft_putstr(char *str);
void	ft_identifier(char c, va_list arg, t_struct *params);
void	ft_putnumber_base(long long int, char *base);
void	ft_precision(const char *str, int i, t_struct *params);
void	ft_print_params(t_struct *params);


#endif
