/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_45.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 13:44:24 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/09 10:06:14 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Pushes numbers back to stack a until stack b is empty.
*/
static void	push_until_empty(t_stack **a, t_stack **b)
{
	int	b_len;

	b_len = stack_len(b);
	while (b_len > 0)
	{
		push(a, b);
		b_len--;
	}
}

/*
** Finds the corresponding index number.
*/
int	get_index(t_stack **s, int min)
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
void	push_min(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;
	int		count;

	tmp = *a;
	min = get_min(a);
	count = get_index(a, min);
	if (count > 2)
	{
		while (tmp->nb != min)
			rev_rotate(&tmp);
		*a = tmp;
	}
	else
	{
		while (tmp->nb != min)
			rotate(&tmp);
		*a = tmp;
	}
	push(b, a);
}

/*
** Sorts 5 numbers.
*/
static void	sort_5(t_stack **a, t_stack **b, int s_len)
{
	int	min;
	int	max;

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
		push(a, b);
		s_len--;
	}
	push_until_empty(a, b);
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
			swap(a);
		while (s_len >= 1)
		{
			push(a, b);
			s_len--;
		}
	}
	else
		sort_5(a, b, s_len);
}
