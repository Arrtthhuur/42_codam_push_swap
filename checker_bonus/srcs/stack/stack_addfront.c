/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_addfront.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 13:46:15 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/02 15:39:51 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Adds a new element to the front of the stack.
**		Sets value and index of new element.
*/
void	stack_addfront(t_stack **s, int value, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error_exit();
	new->value = value;
	new->index = index;
	new->next = *s;
	*s = new;
}
