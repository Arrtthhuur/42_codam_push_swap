/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 15:12:58 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/21 18:26:19 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		count_digits(t_stack **a)
{
	int	nb_digit;
	int	max;
	
	max = get_max(a);
	nb_digit = 0;
	while (max > 0)
	{
		max = max / 10;
		nb_digit++;
	}
	return (nb_digit);
}

static t_stack	*return_max(t_stack **a, int max)
{
	t_stack	*tmp;
	t_stack	*tmp_stack;

	tmp = NULL;
	tmp_stack = *a;
	while (tmp_stack != NULL)
	{
		if (max == tmp_stack->value)
		{
			tmp = tmp_stack;
			tmp_stack = tmp_stack->next;
			return (tmp);
		}
		tmp_stack = tmp_stack->next;
	}
	return (NULL);
}

static void		delete_max(t_stack **a, t_stack **b, int max)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = *a;
	// prev = *a;
	if (tmp != NULL && tmp->value == max)
	{
		push(a, b, STACK_B);
		*a = tmp->next;
		// free(tmp);
	}
	while (tmp != NULL && tmp->value != max)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		// return (NULL);
	prev->next = tmp->next;
	// free(tmp);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		max;

	max = get_max(a);
	delete_max(a, b, max);
	stack_print(*a, STACK_A);
	stack_print(*b, STACK_B);
	// tmp = return_max(a, max);
	// stack_print(tmp, 't');
	// push(&tmp, b, STACK_B);
	// push(&tmp, &b, STACK_B);
	// stack_print(*b, STACK_B);
}
