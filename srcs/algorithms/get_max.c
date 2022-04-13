/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_max.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 10:44:49 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/13 13:00:50 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	return (max);
}
