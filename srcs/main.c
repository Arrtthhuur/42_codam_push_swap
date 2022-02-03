/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 13:54:11 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/03 14:22:59 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 1)
		return (1);
	a = NULL;
	input_parser(&a, argv);
	return (0);
}
