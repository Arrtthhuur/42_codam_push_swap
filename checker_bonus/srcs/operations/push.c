/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:50:22 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/05 10:44:35 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Take the first element at the top of src and put it at the top of dst.
** 		Do nothing if src is empty.
*/
void	push(t_stack **dst, t_stack **src)
{	
	t_stack	*temp;

	if (src == NULL)
		return ;
	temp = *src;
	if (temp->next)
		*src = temp->next;
	else
		*src = NULL;
	temp->next = *dst;
	*dst = temp;
}
