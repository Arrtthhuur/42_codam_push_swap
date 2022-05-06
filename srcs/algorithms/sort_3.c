/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 11:37:12 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/06 17:19:09 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Returns the sorting case.
*/
static int	check_sorting_case(t_stack *stack, int min, int max)
{
	int	count;

	count = 0;
	while (stack->next != NULL)
	{
		if (stack->nb == max && count == 0)
			if (stack->next->nb == min)
				return (2);
		if (stack->nb == max && count == 1)
		{
			if (stack->next->nb != min)
				return (3);
			return (4);
		}
		if (stack->nb > stack->next->nb)
		{
			if (stack->next->nb > stack->next->next->nb)
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
