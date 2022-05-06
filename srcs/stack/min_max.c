/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   min_max.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 10:44:49 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/06 17:20:18 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Returns max element of stack.
*/
int	get_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = INT_MIN;
	while (tmp != NULL)
	{
		if (max < tmp->nb)
			max = tmp->nb;
		tmp = tmp->next;
	}
	// if (max < tmp->nb)
	// 	max = tmp->nb;
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
	while (tmp != NULL)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	// if (min > tmp->nb)
	// 	min = tmp->nb;
	return (min);
}
