/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_index.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 13:43:55 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/06 17:20:23 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Loops over stack until we reach the position of the number we
** 	want to change the index of.
*/
static void	apply_index(t_stack **stack, int position, int to_set)
{
	t_stack	*tmp;

	tmp = *stack;
	while (position > 1)
	{
		tmp = tmp->next;
		position--;
	}
	tmp->index = to_set;
}

/*
** Loops over stack, incrementing current (= index of current element).
** 	If index is not already set:
**		If nb is equals to INT_MIN, index is 1.
**		Else nb is greater than max, this nb becomes max and index is current.
**	588 0 1
**		Nb 1: 588 => > max => index = current = 1 => current++
**		Nb 2: 0 => < max => index = -1 => current++
**		Nb 3: 1 => < max => index = -1 => current++
**		Nb 4: 600 => > max => index = current = 4 => current++
**		Return index = 4
*/
static int	get_max_set_index(t_stack **stack)
{
	t_stack	*tmp;
	int		max;
	int		index;
	int		current;

	tmp = *stack;
	max = INT_MIN;
	index = -1;
	current = 1;
	while (tmp != NULL)
	{
		if (tmp->index == -1)
		{
			if (tmp->nb == INT_MIN)
				tmp->index = 1;
			else if (tmp->nb > max)
			{
				max = tmp->nb;
				index = current;
			}
		}
		tmp = tmp->next;
		current++;
		
	}
	return (index);
}

/*
** Loops over stack len to go over each element of the stack.
**	Finds max nb and applies index starting at 1.
*/
void	stack_index(t_stack **stack)
{
	t_stack	*tmp;
	int		index;
	int		s_len;

	tmp = *stack;
	s_len = stack_len(stack);
	while (s_len > 0)
	{
		index = get_max_set_index(stack);
		if (index == -1)
			break ;
		apply_index(stack, index, s_len);
		s_len--;
	}
}
