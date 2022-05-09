/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_hexlong_conv.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 18:39:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/05 17:30:55 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** File with unsigned long long to hex conversion and print
*/

static int	ft_print_hex(char *hexadecimalnum, int j)
{
	int	i;
	int	count;

	i = j - 1;
	count = ft_strlen(hexadecimalnum);
	while (i >= 0)
	{
		ft_putchar(ft_tolower(hexadecimalnum[i]));
		i--;
	}
	return (count);
}

int	ft_hexlong_conv(unsigned long long decimalnum)
{
	unsigned long long		quotient;
	unsigned long long		remainder;
	int						j;
	char					hexadecimalnum[100];
	int						count;

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
	count = ft_print_hex(hexadecimalnum, j);
	return (count);
}
