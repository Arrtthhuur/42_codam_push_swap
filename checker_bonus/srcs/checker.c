/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 14:29:05 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/12 09:44:57 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Execute the given instruction, or error. [1/2]
*/
static void	exec_instr2(char *op, t_stack **a, t_stack **b)
{
	if (ft_strncmp(op, "pa", 2) == 0)
		push(a, b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		push(b, a);
	else if (ft_strncmp(op, "rra", 3) == 0)
		rev_rotate(a);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		rev_rotate(b);
	else if (ft_strncmp(op, "rrr", 3) == 0)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		error_exit();
}

/*
** Execute the given instruction, or error. [1/2]
*/
static void	exec_instr1(char *op, t_stack **a, t_stack **b)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		swap(a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		swap(b);
	else if (ft_strncmp(op, "ra", 2) == 0)
		rotate(a);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rotate(b);
	else if (ft_strncmp(op, "rr", 2) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else
		exec_instr2(op, a, b);
}

/*
** Read one char at a time until EOF (nbytes = 0).
*/
static int	read_char(char *c)
{
	int	nbytes;

	nbytes = read(0, c, 1);
	nbytes = -1;
	if (nbytes < 0)
		return (EXIT_FAILURE);
	if (nbytes == 0)
		return (4);
	return (EXIT_SUCCESS);
}

/*
** Read from stdin and break when CTRL+D is pressed.
*/
static int	read_input(t_stack **a, t_stack **b, char *instruction)
{
	char	c;
	int		ret;
	int		i;

	i = 0;
	while (1)
	{
		ret = read_char(&c);
		if (ret == 1)
			return (EXIT_FAILURE);
		else if (ret == 4)
			break ;
		else
		{
			instruction[i] = c;
			if (c == '\n')
			{
				exec_instr1(instruction, a, b);
				reset(instruction);
				i = -1;
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

/*
** Main function.
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	instruction[4];

	if (argc == 1)
		return (EXIT_SUCCESS);
	stack_a = NULL;
	stack_b = NULL;
	input_parser(argv, argc, &stack_a);
	read_input(&stack_a, &stack_b, instruction);
	if (is_sorted(&stack_a) == EXIT_SUCCESS && stack_b == NULL)
		return (success_exit());
	return (failure_exit());
}
