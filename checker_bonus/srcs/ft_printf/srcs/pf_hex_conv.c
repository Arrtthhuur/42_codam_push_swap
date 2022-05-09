/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_hex_conv.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 18:39:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/05 17:30:51 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** File with unsigned int to hex conversion and print
*/

static int	ft_print_hex(char *hexadecimalnum, int j, int format)
{
	int	i;

	i = j - 1;
	while (i >= 0)
	{
		if (format == 1)
			ft_putchar(ft_tolower(hexadecimalnum[i]));
		else if (format == 2)
			ft_putchar(hexadecimalnum[i]);
		i--;
	}
	return (0);
}

int	ft_hex_conv(unsigned int decimalnum, int format)
{
	unsigned int		quotient;
	unsigned int		remainder;
	int					j;
	char				hexadecimalnum[100];
	int					count;

	j = 0;
	quotient = decimalnum;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			remainder += 48;
		else
			remainder += 55;
		hexadecimalnum[j] = remainder;
		j++;
		quotient = quotient / 16;
	}
	hexadecimalnum[j] = '\0';
	count = ft_strlen(hexadecimalnum);
	ft_print_hex(hexadecimalnum, j, format);
	return (count);
}
