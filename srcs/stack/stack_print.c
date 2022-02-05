/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_print.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 14:58:44 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/05 15:52:09 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

t_stack	*stack_reverse(t_stack *head)
{
	t_stack	*prev;
	t_stack	*current;
	t_stack	*next;

	prev = NULL;
	current = head;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return (head);
}

void	stack_print(t_stack *a)
{
	while (a->next != NULL)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	printf("%d\n", a->value);
}
