/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 14:29:05 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/02 15:57:12 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int read_char(char *c)
{
    char    nbytes;

    nbytes = read(0, &c, 1);
    if (nbytes < 0)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int read_input(void)
{
    char    c;

    while (1)
    {
        if (read_char(&c) == 1)
            return (EXIT_FAILURE);
        // ft_printf("%s\n", c);
        if (c == '\n')
            break ;
    }
    return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

    if (argc == 1)
        error_exit();
    stack_a = NULL;
	stack_b = NULL;
	input_parser(argv, argc, &stack_a);
	if (is_sorted(&stack_a) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
    read_input();
    return (EXIT_FAILURE);
}
