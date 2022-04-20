/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_len.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:18:08 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/18 14:45:26 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Returns length of stack.
*/
int	stack_len(t_stack **stack)
{
	t_stack	*tmp;
	int		len;

	tmp = *stack;
	len = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
