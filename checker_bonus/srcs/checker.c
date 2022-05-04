/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 14:29:05 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/04 16:28:22 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** Reset the operation array.
*/
void	reset(char *op)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		op[i] = 0;
		i++;
	}
}

/*
** Execute the given operation, or error.
*/
void	exec_op(char *op, t_stack **a, t_stack **b)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		swap(a);
	if (ft_strncmp(op, "sb", 2) == 0)
		swap(b);
	if (ft_strncmp(op, "ra", 2) == 0)
		rotate(a);
	if (ft_strncmp(op, "rb", 2) == 0)
		rotate(b);
	if (ft_strncmp(op, "rr", 2) == 0)
	{
		rotate(a);
		rotate(b);
	}
	if (ft_strncmp(op, "pa", 2) == 0)
		push(a, b);
	if (ft_strncmp(op, "pb", 2) == 0)
		push(b, a);
	if (ft_strncmp(op, "rra", 3) == 0)
		rev_rotate(a);
	if (ft_strncmp(op, "rrb", 3) == 0)
		rev_rotate(b);
	if (ft_strncmp(op, "rrr", 3) == 0)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		error_exit();
}

/*
** Read one char at a time until EOF (nbytes = 0).
*/
int read_char(char *c)
{
    int	nbytes;

    nbytes = read(0, c, 1);
    if (nbytes < 0)
        return (EXIT_FAILURE);
	if (nbytes == 0)
		return (4);
    return (EXIT_SUCCESS);
}

/*
** Read from stdin and break when CTRL+D is pressed.
*/
int read_input(t_stack **a, t_stack **b)
{
    char    c;
	char	operation[4];
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
			operation[i] = c;
			if (c == '\n')
			{
				exec_op(operation, a, b);
				reset(operation);
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
int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

    if (argc == 1)
        return (EXIT_SUCCESS);
    stack_a = NULL;
	stack_b = NULL;
	input_parser(argv, argc, &stack_a);
    read_input(&stack_a, &stack_b);
	if (is_sorted(&stack_a) == EXIT_SUCCESS)
		return (success_exit());
    return (failure_exit());
}
