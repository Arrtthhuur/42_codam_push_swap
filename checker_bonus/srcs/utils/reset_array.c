/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_array.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 14:52:23 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/05 14:52:35 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Reset the operation array.
*/
void	reset(char *op)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		op[i] = 0;
		i++;
	}
}
