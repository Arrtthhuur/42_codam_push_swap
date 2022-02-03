/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 16:08:32 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/03 14:27:31 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

static int	check_big(char *value)
{
	long long	tmp;

	tmp = ft_atoll(value);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_int(char *value)
{
	if (*value == '-')
		value++;
	if (!*value)
		return (1);
	while (*value)
	{
		if (!ft_isdigit(*value))
			return (1);
		value++;
	}
	return (0);
}

static void	check_dup(t_stack *start)
{
	t_stack	*index;
	t_stack	*curr;

	index = start;
	while (index != NULL && index->next != NULL)
	{
		curr = index;
		while (curr->next != NULL)
		{
			if (index->value == curr->next->value)
				error_exit();
			curr = curr->next;
		}
		index = index->next;
	}
}

static void	print_stack(t_stack *a)
{
	while (a->next != NULL)
	{
		printf("[%d] %d\n", a->index, a->value);
		a = a->next;
	}
	printf("[%d] %d\n", a->index, a->value);
}

void	input_parser(t_stack **a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_int(argv[i]))
			error_exit();
		if (check_big(argv[i]))
			error_exit();
		ps_lstadd_front(a, ft_atoi(argv[i]));
		i++;
	}
	check_dup(*a);
	print_stack(*a);
}
