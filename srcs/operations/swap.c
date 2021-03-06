/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 14:32:44 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/06 17:19:55 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Swap the first 2 elements at the top of stack a.
** 		Do nothing if there is only one or no elements.
*/
void	swap(t_stack **stack, char stack_name)
{
	t_stack	*elem1;
	t_stack	*elem2;

	elem1 = *stack;
	elem2 = elem1->next;
	if (!elem1 || !elem2)
		return ;
	elem1->next = elem1->next->next;
	elem2->next = elem1;
	*stack = elem2;
	ft_printf("s");
	ft_printf("%c\n", stack_name);
}
