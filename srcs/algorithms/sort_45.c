/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_45.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 13:44:24 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/07 18:38:21 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Finds the corresponding index number.
*/
static int	get_min_index(t_stack **s, int min)
{
	t_stack	*tmp;
	int		count;

	tmp = *s;
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->nb == min)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (-1);
}

/*
** Pushes min number to stack b.
*/
static void	push_min(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;
	int		count;

	tmp = *a;
	min = get_min(a);
	count = get_min_index(a, min);
	if (count > 2)
	{
		while (tmp->nb != min)
			rev_rotate(&tmp, STACK_A);
		*a = tmp;
	}
	else
	{
		while (tmp->nb != min)
			rotate(&tmp, STACK_A);
		*a = tmp;
	}
	push(b, a, STACK_B);
}

/*
** Sorts 5 numbers.
*/
static void	sort_5(t_stack **a, t_stack **b, int s_len)
{
	int	min;
	int	max;
	int	len;

	while (s_len > 3)
	{
		push_min(a, b);
		s_len--;
	}
	if (is_sorted(a) != EXIT_SUCCESS)
	{
		min = get_min(a);
		max = get_max(a);
		sort_3(a, min, max);
	}
	while (s_len > 1)
	{
		push(a, b, STACK_A);
		s_len--;
	}
	len = stack_len(b);
	while (len > 0)
	{
		push(a, b, STACK_A);
		len--;
	}
}

/*
** Sorts 4 and 5 numbers.
*/
void	sort_45(t_stack **a, t_stack **b)
{
	int	s_len;

	s_len = stack_len(a);
	if (s_len == 4)
	{
		while (s_len > 2)
		{
			push_min(a, b);
			s_len--;
		}
		if (is_sorted(a) != EXIT_SUCCESS)
			swap(a, STACK_A);
		while (s_len >= 1)
		{
			push(a, b, STACK_A);
			s_len--;
		}
	}
	else
		sort_5(a, b, s_len);
}
