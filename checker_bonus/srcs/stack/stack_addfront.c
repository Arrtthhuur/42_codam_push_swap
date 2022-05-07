/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_addfront.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 13:46:15 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/07 16:54:19 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Adds a new element to the front of the stack.
**		Sets value and index of new element.
*/
void	stack_addfront(t_stack **stack, int nb, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error_exit();
	new->nb = nb;
	new->index = index;
	new->next = *stack;
	*stack = new;
}
