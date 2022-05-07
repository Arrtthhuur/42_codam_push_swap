/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 15:12:58 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/07 18:45:19 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_index(t_stack **ref, int index)
{
	t_stack	*temp;

	temp = *ref;
	while (temp->next && index > 0)
	{
		temp = temp->next;
		index--;
	}
	return (temp->index);
}

void	radix_sort(t_stack **a, t_stack **b)
{
    int size = stack_len(a);
    for (int i = 0 ; is_sorted(a) != 0 ; ++i)
    {
        for (int j = 0 ; j < size ; ++j)
        {
            int num = get_index(a, 0);
            if ((num >> i)&1)
                rotate(a, STACK_A);
            else 
                push(b, a, STACK_B);
        }
        int len = stack_len(b);
        while (len > 0)
        {
            push(a, b, STACK_A);
            len--;
        }
    }
}
