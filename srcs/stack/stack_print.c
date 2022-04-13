/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_print.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 14:58:44 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/13 16:11:50 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	stack_print(t_stack *s)
{
	while (s->next != NULL)
	{
		ft_printf("[%d]: %d\n", s->index, s->value);
		s = s->next;
	}
	ft_printf("[%d]: %d\n", s->index, s->value);
	ft_printf("     -\n     a\n\n");
}
