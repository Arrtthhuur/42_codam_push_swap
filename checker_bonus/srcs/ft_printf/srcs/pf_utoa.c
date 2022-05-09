/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_utoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 13:37:14 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/05 17:31:46 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** File with unsigned int to str
*/

static size_t	ft_uintlen(unsigned int ui)
{
	size_t			len;
	unsigned int	num;

	len = 0;
	num = ui;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int ui)
{
	char			*ptr;
	size_t			len;
	unsigned int	num;

	len = ft_uintlen(ui);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	num = ui;
	if (ui == 0)
		ptr[0] = '0';
	while (num > 0)
	{
		len--;
		ptr[len] = num % 10 + '0';
		num /= 10;
	}
	return (ptr);
}
