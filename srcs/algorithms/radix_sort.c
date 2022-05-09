/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 15:12:58 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/09 10:07:30 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Pushes numbers back to stack a until stack b is empty.
*/
static void	push_until_empty(t_stack **a, t_stack **b)
{
	int	b_len;

	b_len = stack_len(b);
	while (b_len > 0)
	{
		push(a, b, STACK_A);
		b_len--;
	}
}

/*
** Gets the number at given index.
*/
static int	get_index(t_stack **stack, int index)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next && index > 0)
	{
		tmp = tmp->next;
		index--;
	}
	return (tmp->index);
}

/*
** Sorts more than 5 numbers using radix sort.
**	Until a is sorted
**		Until we go over all elements of the stack (= stack_len)
**			Get the nb at the start of the stack
**			If nb bit-shifted by i (= i-th digit of the nb) is 1
**				We rotate the stack to keep this nb in a
**			Else nb is 0 (+- = smallest numbers)
**				We push it to b
**			We then push everything back to a
**			And repeat this for the nb of digits
*/
void	radix_sort(t_stack **a, t_stack **b, int s_len)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (is_sorted(a) != 0)
	{
		j = 0;
		while (j < s_len)
		{
			nb = get_index(a, 0);
			if (((nb >> i) & 1) == 1)
				rotate(a, STACK_A);
			else
				push(b, a, STACK_B);
			j++;
		}
		push_until_empty(a, b);
		i++;
	}
}
