/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 16:08:32 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/05 16:02:03 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

static int	check_only_int(char *value)
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

static int	check_bigger_int(char *value)
{
	long long	tmp;

	tmp = ft_atoll(value);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	check_duplicates(t_stack *head)
{
	t_stack	*curr;
	t_stack	*tmp;

	curr = head;
	while (curr != NULL)
	{
		tmp = curr;
		while (tmp->next != NULL)
		{
			if (curr->value == tmp->next->value)
				error_exit();
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}

void	input_parser(t_stack **a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_only_int(argv[i]))
			error_exit();
		if (check_bigger_int(argv[i]))
			error_exit();
		stack_addfront(a, ft_atoi(argv[i]));
		i++;
	}
	check_duplicates(*a);
	*a = stack_reverse(*a);
}
