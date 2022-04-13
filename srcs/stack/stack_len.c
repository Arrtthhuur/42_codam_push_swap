/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_len.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:18:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/13 13:00:54 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	stack_len(t_stack **stack)
{
	t_stack	*tmp;
	size_t	len;

	tmp = *stack;
	len = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
