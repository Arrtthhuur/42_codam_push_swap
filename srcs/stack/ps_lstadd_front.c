/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 13:46:15 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/03 13:48:21 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define NaN -1

void	ps_lstadd_front(t_stack **s, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error_exit();
	new->value = value;
	new->index = NaN;
	new->next = *s;
	*s = new;
}
