/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_message.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 15:57:26 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/04 11:37:53 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

#include <unistd.h> // write

int	error_msg(char *msg)
{
	write(2, "Error\n\t", 7);
	if (msg)
		write(2, msg, ft_strlen(msg));
	return (EXIT_FAILURE);
}

int	success_msg(char *msg)
{
	write(2, "Success\n\t", 9);
	if (msg)
		write(2, msg, ft_strlen(msg));
	return (EXIT_SUCCESS);
}

void	error_exit(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

int	success_exit(void)
{
	write(1, "OK\n", 4);
	return (EXIT_SUCCESS);
}

int	failure_exit(void)
{
	write(1, "KO\n", 4);
	return (EXIT_FAILURE);
}
