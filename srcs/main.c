/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 13:54:11 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/13 16:25:34 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		max;
	size_t	s_len;

	if (argc == 1)
		return (EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	input_parser(argv, argc, &stack_a);
	s_len = stack_len(&stack_a);
	stack_print(stack_a);
	radix_sort(stack_a, stack_b, s_len);
	// stack_print(stack_a);
	swap(&stack_a);
	// stack_print(stack_a, stack_b);
	rotate(&stack_a);
	// stack_print(stack_a, stack_b);
	max = get_max(&stack_a);
	printf("max_a = %d\n", max);
	printf("len = %zu\n\n", stack_len(&stack_a));
	push(&stack_a, &stack_b);
	// stack_print(stack_a, stack_b);
	push(&stack_a, &stack_b);
	// stack_print(stack_a, stack_b);
	push(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
