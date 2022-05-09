/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_conversions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/02 13:06:02 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/17 16:32:49 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** File with all the conversion formats using va_arg
*/

char	ft_format_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (c);
}

int	ft_format_di(va_list args)
{
	int	d;

	d = va_arg(args, int);
	return (d);
}

unsigned long long	ft_format_p(va_list args)
{
	unsigned long long	p;

	p = (unsigned long long) va_arg(args, void *);
	return (p);
}

char	*ft_format_s(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	return (s);
}

unsigned int	ft_format_uxx(va_list args)
{
	unsigned int	ui;

	ui = va_arg(args, unsigned int);
	return (ui);
}
