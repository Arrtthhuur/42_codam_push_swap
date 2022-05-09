/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_format_print.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/02 13:25:07 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/17 16:33:02 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** File with all the print functions according 
** to the conversion format (see pf_conversions.c) 
*/

int	ft_cprintf(va_list args)
{
	char	c;
	int		count;

	c = ft_format_c(args);
	count = 1;
	ft_putchar(c);
	return (count);
}

int	ft_sprintf(va_list args)
{
	char	*s;
	int		count;

	s = ft_format_s(args);
	if (s == NULL)
	{
		ft_putstr("(null)");
		count = 6;
	}
	else
	{
		ft_putstr(s);
		count = ft_strlen(s);
	}
	return (count);
}

int	ft_diprintf(va_list args)
{
	int	d;
	int	count;

	d = ft_format_di(args);
	ft_putnbr(d);
	count = ft_intlen(d);
	return (count);
}

int	ft_pprintf(va_list args)
{
	unsigned long long	p;
	int					count;

	p = ft_format_p(args);
	ft_putstr("0x");
	count = 2;
	if (p == 0)
	{
		ft_putchar('0');
		count += 1;
	}
	else
		count += ft_hexlong_conv(p);
	return (count);
}

int	ft_uxxprintf(va_list args, const char *fmt, int len)
{
	unsigned int	ui;
	int				count;

	ui = ft_format_uxx(args);
	if (ui == 0)
	{
		ft_putchar('0');
		count = 1;
	}
	else
	{
		count = 0;
		if (fmt[len] == 'x')
			count = ft_hex_conv(ui, 1);
		else if (fmt[len] == 'X')
			count = ft_hex_conv(ui, 2);
		else if (fmt[len] == 'u')
			count = ft_uprintf(ui);
	}
	return (count);
}
