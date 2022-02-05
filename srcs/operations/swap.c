/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 14:32:44 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/05 16:03:59 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*elem1;
	t_stack	*elem2;

	elem1 = *stack;
	elem2 = elem1->next;
	elem1->next = elem1->next->next;
	elem2->next = elem1;
	*stack = elem2;
}
