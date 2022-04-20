/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 13:44:24 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/18 15:09:23 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Sorts stack of 4 elements.
** 	Not required by eval sheet but still...
** 		Push 2 elements to stack b.
**		Sort stack a, unsort stack b.
**		Push elements of stack b to stack a.
*/
void	sort_45(t_stack **a, t_stack **b)
{
	push(a, b, STACK_B);
	push(a, b, STACK_B);
	if (is_sorted(a) != EXIT_SUCCESS)
		swap(a, STACK_A);
	if (is_sorted(b) == EXIT_SUCCESS)
		swap(b, STACK_B);
	push(b, a, STACK_A);
	push(b, a, STACK_A);
}
