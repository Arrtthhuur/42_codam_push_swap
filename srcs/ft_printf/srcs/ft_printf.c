/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 18:40:57 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/17 16:38:31 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** File with ft_printf and parsing functions
*/

static int	ft_parsing(va_list args, const char *fmt, int len)
{
	int	count;

	count = 0;
	if (fmt[len] == 'c')
		count += ft_cprintf(args);
	else if (fmt[len] == 's')
		count += ft_sprintf(args);
	else if (fmt[len] == 'd' || fmt[len] == 'i')
		count += ft_diprintf(args);
	else if (fmt[len] == 'p')
		count += ft_pprintf(args);
	else if (fmt[len] == 'x' || fmt[len] == 'X'
		|| fmt[len] == 'u')
		count += ft_uxxprintf(args, fmt, len);
	else if (fmt[len] == '%')
	{
		ft_putchar('%');
		count += 1;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;
	int		count;			

	va_start(args, fmt);
	len = 0;
	count = 0;
	while (fmt[len])
	{
		if (fmt[len] == '%')
		{
			len++;
			count += ft_parsing(args, fmt, len);
		}
		else
		{
			ft_putchar(fmt[len]);
			count++;
		}
		len++;
	}
	va_end(args);
	return (count);
}
