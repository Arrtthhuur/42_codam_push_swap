/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_index.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 13:43:55 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/07 16:30:45 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Loops over stack until we reach the position of the number we
** 	want to apply the new index to.
*/
static void	apply_index(t_stack **stack, int position, int new_index)
{
	t_stack	*tmp;

	tmp = *stack;
	while (position > 1)
	{
		tmp = tmp->next;
		position--;
	}
	tmp->index = new_index;
}

/*
** Loops over stack, incrementing current (= index of current element).
** 	If index is not already set (= -1)
**		If nb is >= max, this nb becomes max and index is current.
**	ex: 588 0 1 600
**		Nb 1: 588 > max => index = current = 1 => current++
**		Nb 2: 0 < max => index = -1 => current++
**		Nb 3: 1 < max => index = -1 => current++
**		Nb 4: 600 > max => index = current = 4 => current++
**		Return index = 4
*/
static int	get_max_position(t_stack **stack)
{
	t_stack	*tmp;
	int		max;
	int		index;
	int		curr;

	tmp = *stack;
	max = INT_MIN;
	index = -1;
	curr = 1;
	while (tmp != NULL)
	{
		if (tmp->index == -1)
		{
			if (tmp->nb >= max)
			{
				max = tmp->nb;
				index = curr;
			}
		}
		tmp = tmp->next;
		curr++;
	}
	return (index);
}

/*
** Loops over stack len to go over each element of the stack.
**	Finds max nb and applies index starting at 1.
** 		s_len is going to be the index of each element
**		index is the position of the max
**	ex: 588 0 1 600
**		s_len = 4
**		go into get_max_set_index
**		index = 4
**		600 is located on index 4 and will have new index (= s_len) 4, s_len--
**		s_len = 3
**		go into get_max_set_index
**		index = 1
**		588 is loc on i 1 and will have new i (= s_len) 3	
*/
void	stack_index(t_stack **stack)
{
	int		position;
	int		new_index;

	new_index = stack_len(stack);
	while (new_index > 0)
	{
		position = get_max_position(stack);
		if (position == -1)
			break ;
		apply_index(stack, position, new_index);
		new_index--;
	}
}
