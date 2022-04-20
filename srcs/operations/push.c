/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:50:22 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/18 14:03:00 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Take the first element at the top of src and put it at the top of dst.
** 		Do nothing if src is empty.
*/
void	push(t_stack **src, t_stack **dst, char stack_name)
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
	ft_printf("p");
	ft_printf("%c\n", stack_name);
}
