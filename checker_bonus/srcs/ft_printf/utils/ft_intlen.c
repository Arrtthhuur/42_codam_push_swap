/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 15:10:10 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/04 20:39:38 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

size_t	ft_intlen(long n)
{
	size_t			len;
	unsigned int	num;

	len = 0;
	if (n <= 0)
	{
		num = n * -1;
		len++;
	}
	else
		num = n;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}
