/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:37:17 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/12 15:49:13 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack)
		return ;
	first = *stack;
	last = *stack;
	*stack = first->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
}
