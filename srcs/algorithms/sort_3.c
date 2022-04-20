/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 11:37:12 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/18 14:46:43 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Returns the sorting case.
*/
static int	check_sorting_case(t_stack *stack, int min, int max)
{
	while (stack->next != NULL)
	{
		if (stack->value == max && stack->index == 2)
			if (stack->next->value == min)
				return (2);
		if (stack->value == max && stack->index == 1)
		{
			if (stack->next->value != min)
				return (3);
			else
				return (4);
		}
		if (stack->value > stack->next->value)
		{
			if (stack->next->value > stack->next->next->value)
				return (5);
			else
				return (6);
		}
		stack = stack->next;
	}
	return (EXIT_FAILURE);
}

/*
** Sorts stack of 3 elements.
*/
void	sort_3(t_stack **stack, int min, int max)
{
	int	s_case;

	s_case = check_sorting_case(*stack, min, max);
	if (s_case == 2)
		rotate(stack, STACK_A);
	if (s_case == 3)
	{
		swap(stack, STACK_A);
		rotate(stack, STACK_A);
	}
	if (s_case == 4)
	{
		rotate(stack, STACK_A);
		rotate(stack, STACK_A);
	}
	if (s_case == 5)
	{
		rotate(stack, STACK_A);
		swap(stack, STACK_A);
	}
	if (s_case == 6)
		swap(stack, STACK_A);
}
