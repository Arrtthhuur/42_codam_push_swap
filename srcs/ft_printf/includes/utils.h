/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 15:53:54 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/05 19:26:23 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libftprintf.h"

# include <stdlib.h> // size_t

size_t	ft_intlen(long n);

void	ft_putchar(char c);

void	ft_putnbr(int nb);

void	ft_putstr(char *str);

size_t	ft_strlen(const char *s);

int		ft_tolower(int c);

#endif
