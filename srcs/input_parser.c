/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 16:08:32 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/09 10:27:56 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

/*
** Checks that the value only contains integers.
*/
static int	check_only_int(char *value)
{
	if (*value == '-')
		value++;
	if (!*value)
		return (EXIT_FAILURE);
	while (*value)
	{
		if (!ft_isdigit(*value))
			return (EXIT_FAILURE);
		value++;
	}
	return (EXIT_SUCCESS);
}

/*
** Checks that the value is not bigger than int.
*/
static int	check_bigger_int(char *value)
{
	long long	tmp;

	tmp = ft_atoll(value);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
** Converts and fills the array with given arguments.
*/
static int	*fill_array(char **argv, int len)
{
	int		*array;
	int		x;
	int		y;

	x = len - 1;
	y = 0;
	array = (int *) malloc((len) * sizeof(array));
	if (!array)
		return (NULL);
	while (x > 0)
	{
		array[y] = ft_atoi(argv[x]);
		y++;
		x--;
	}
	array[y] = '\0';
	return (array);
}

/*
** Checks for duplicates within the newly created array.
*/
static int	check_duplicates(int *array, int argc)
{
	int	i;
	int	x;

	i = 0;
	while (argc > i)
	{
		x = i - 1;
		while (x >= 0)
		{
			if (array[x] == array[i])
				return (EXIT_FAILURE);
			x--;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
** Parses the input, 
**	checks for only ints, 
**	bigger than ints, 
**	duplicates 
**	and then adds the values to the stack a.
*/
void	input_parser(char **argv, int argc, t_stack **stack)
{
	int	i;
	int	*array;

	i = 1;
	while (argv[i] != NULL)
	{
		if (check_only_int(argv[i]))
			error_exit();
		if (check_bigger_int(argv[i]))
			error_exit();
		i++;
	}
	array = fill_array(argv, argc);
	if (!array)
		error_exit();
	if (check_duplicates(array, argc - 1))
		error_exit();
	i = 0;
	while (i < argc - 1)
	{
		stack_addfront(stack, array[i]);
		i++;
	}
	free(array);
}
