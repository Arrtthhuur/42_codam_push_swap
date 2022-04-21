/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_45.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 13:44:24 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/21 18:01:47 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_index(t_stack **s, int min)
{
	t_stack	*tmp;
	int		count;

	tmp = *s;
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->value == min)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (-1);
}

void	push_min(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int	min;
	int count;

	tmp = *a;
	min = get_min(a);
	count = get_index(a, min);
	if (count > 2)
	{
		while (tmp->value != min)
			rev_rotate(&tmp, STACK_A);
		*a = tmp;	
	}
	else
	{
		while (tmp->value != min)
			rotate(&tmp, STACK_A);
		*a = tmp;	
	}
	push(b, a, STACK_B);
}

void	sort_45(t_stack **a, t_stack **b)
{
	int s_len;
	int	min;
	int	max;
	
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
	{
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
	}
}
