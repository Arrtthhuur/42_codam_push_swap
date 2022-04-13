/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:50:22 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/13 10:18:09 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{	
	t_stack	*temp;

	if (src == NULL)
		return ;
	temp = *src;
	if (temp->next)
		*src = temp->next;
	else
		*src = NULL;
	temp->next = *dest;
	*dest = temp;
}
