/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 13:54:11 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/02 16:08:56 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

// Driver program to test above function
int main(int argc, char **argv)
{
    char **arr;
	char **stack_a;
    int n = sizeof(arr) / sizeof(arr[0]);
	int i;

    if (argc == 1)
        return (1);
	input_parser(&stack_a, argc, argv);
	return (0);
}