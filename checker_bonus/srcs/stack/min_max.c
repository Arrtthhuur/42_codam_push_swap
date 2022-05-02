/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   min_max.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 10:44:49 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/02 15:39:57 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Returns max element of stack.
*/
int	get_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = INT_MIN;
	while (tmp->next != NULL)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	if (max < tmp->value)
		max = tmp->value;
	return (max);
}

/*
** Returns min element of stack.
*/
int	get_min(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = INT_MAX;
	while (tmp->next != NULL)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	if (min > tmp->value)
		min = tmp->value;
	return (min);
}
