/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:37:17 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/04 16:01:37 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Shift up all elements of stack a by 1.
** 		The first element becomes the last one.
*/
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
	// ft_printf("r");
	// ft_printf("%c\n", stack_name);
}

/*
** Shift down all elements of stack a by 1.
** 		The last element becomes the first one.
*/
void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*tmp;

	last = *stack;
	first = *stack;
	if (stack_len(stack) == 0)
		return ;
	while (last->next->next != NULL)
		last = last->next;
	tmp = last->next;
	tmp->next = first;
	*stack = tmp;
	last->next = NULL;
	// ft_printf("rr");
	// ft_printf("%c\n", stack_name);
}
