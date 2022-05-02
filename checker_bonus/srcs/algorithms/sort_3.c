/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 11:37:12 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/02 15:39:40 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Returns the sorting case.
*/
static int	check_sorting_case(t_stack *stack, int min, int max)
{
	int	s_len;
	int	count;

	s_len = stack_len(&stack);
	count = 0;
	while (stack->next != NULL)
	{
		if (stack->value == max && count == 0)
			if (stack->next->value == min)
				return (2);
		if (stack->value == max && count == 1)
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
		count++;
		stack = stack->next;
	}
	return (EXIT_FAILURE);
}

/*
** Sorts stack of 3 elements.
**		123, 132, 213, 231, 312, 321
*/
void	sort_3(t_stack **stack, int min, int max)
{
	int	s_case;

	s_case = check_sorting_case(*stack, min, max);
	if (s_case == 2)
	{
		// 312
		rotate(stack, STACK_A);
	}
	if (s_case == 3)
	{
		// 132
		swap(stack, STACK_A);
		rotate(stack, STACK_A);
	}
	if (s_case == 4)
	{
		// 231
		rotate(stack, STACK_A);
		rotate(stack, STACK_A);
	}
	if (s_case == 5)
	{
		// 321
		rotate(stack, STACK_A);
		swap(stack, STACK_A);
	}
	if (s_case == 6)
	{
		// 213
		swap(stack, STACK_A);
	}
}
