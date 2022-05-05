/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 11:37:12 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/05 10:49:44 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Returns the sorting case.
*/
static int	check_sorting_case(t_stack *stack, int min, int max, int s_len)
{
	int	count;

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
			return (4);
		}
		if (stack->value > stack->next->value)
		{
			if (stack->next->value > stack->next->next->value)
				return (5);
			return (6);
		}
		count++;
		stack = stack->next;
	}
	return (EXIT_FAILURE);
}

/*
** Sorts stack of 3 elements.
**		(in order) 312, 132, 231, 321, 213
*/
void	sort_3(t_stack **stack, int min, int max)
{
	int	s_case;
	int	s_len;

	s_len = stack_len(&stack);
	s_case = check_sorting_case(*stack, min, max, s_len);
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
