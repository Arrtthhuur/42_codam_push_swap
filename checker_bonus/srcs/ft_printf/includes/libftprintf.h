/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 18:43:17 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/17 16:33:18 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "utils.h"

# include <stdarg.h> // va_arg

int					ft_printf(const char *str, ...);

/*
** Formatting functions
*/

char				ft_format_c(va_list args);

char				*ft_format_s(va_list args);

unsigned long long	ft_format_p(va_list args);

int					ft_format_di(va_list args);

unsigned int		ft_format_uxx(va_list args);

/*
** Printing functions
*/

int					ft_cprintf(va_list args);

int					ft_sprintf(va_list args);

int					ft_diprintf(va_list args);

int					ft_pprintf(va_list args);

int					ft_uxxprintf(va_list args, const char *fmt, int len);

int					ft_uprintf(unsigned int ui);

/*
** Conversion functions
*/

int					ft_hex_conv(unsigned int decimalnum, int format);

int					ft_hexlong_conv(unsigned long long decimalnum);

char				*ft_utoa(unsigned int ui);

#endif
