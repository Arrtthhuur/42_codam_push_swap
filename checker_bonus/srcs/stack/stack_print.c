/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_print.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 14:58:44 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/02 15:40:04 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Prints stack (index + value) and displays stack name at the bottom.
*/
void	stack_print(t_stack *s, char stack_name)
{
	t_stack	*tmp;

	tmp = s;
	if (!tmp)
		return ;
	while (tmp->next != NULL)
	{
		ft_printf("[%d]: %d\n", tmp->index, tmp->value);
		tmp = tmp->next;
	}
	ft_printf("[%d]: %d\n", tmp->index, tmp->value);
	ft_printf("     -\n     %c\n\n", stack_name);
}
