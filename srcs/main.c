/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 13:54:11 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/12 15:57:10 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	input_parser(argv, argc, &stack_a);
	stack_print(stack_a, 'a');
	swap(&stack_a);
	stack_print(stack_a, 'a');
	rotate(&stack_a);
	stack_print(stack_a, 'a');
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	// stack_print(stack_a, 'a');
	stack_print(stack_b, 'b');
	return (EXIT_SUCCESS);
}
