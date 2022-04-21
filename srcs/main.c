/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 13:54:11 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/21 18:22:58 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Applies sorting algorithm based on length of stack a.
*/
void	apply_sort(t_stack **a, t_stack **b)
{
	int	s_len;
	int	min;
	int	max;

	s_len = stack_len(a);
	min = get_min(a);
	max = get_max(a);
	if (s_len == 2)
		swap(a, STACK_A);
	else if (s_len == 3)
		sort_3(a, min, max);
	else if (s_len == 4 || s_len == 5)
		sort_45(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	input_parser(argv, argc, &stack_a);
	if (is_sorted(&stack_a) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	apply_sort(&stack_a, &stack_b);
	if (is_sorted(&stack_a) == EXIT_SUCCESS)
	{
		// ft_printf("\n\tSORTED\n");
		// stack_print(stack_a, STACK_A);
		// system("leaks push_swap");
		return (EXIT_SUCCESS);
	}
	// ft_printf("\n\tNOT SORTED!\n");
	// stack_print(stack_a, STACK_A);
	// system("leaks push_swap");
	return (EXIT_FAILURE);
}
