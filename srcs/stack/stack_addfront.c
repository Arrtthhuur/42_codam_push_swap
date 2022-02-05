/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_addfront.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 13:46:15 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/05 15:51:54 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_addfront(t_stack **s, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error_exit();
	new->value = value;
	new->next = *s;
	*s = new;
}
