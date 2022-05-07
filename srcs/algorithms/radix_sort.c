/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 15:12:58 by abeznik       #+#    #+#                 */
/*   Updated: 2022/05/07 22:19:59 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void  push_until_empty(t_stack **a, t_stack **b)
{
    int b_len;

    b_len = stack_len(b);
    while (b_len > 0)
    {
        push(a, b, STACK_A);
        b_len--;
    }
}

static int	get_index(t_stack **ref, int index)
{
	t_stack	*tmp;

	tmp = *ref;
	while (tmp->next && index > 0)
	{
		tmp = tmp->next;
		index--;
	}
	return (tmp->index);
}

/*
** Sorts more than 5 numbers using radix sort.
*/
void	radix_sort(t_stack **a, t_stack **b, int s_len)
{
    int i;
    int j;
    int num;
    
    i = 0;
    while (is_sorted(a) != 0)
    {
        j = 0;
        while (j < s_len)
        {
            num = get_index(a, 0);
            ft_printf("%d => %d", num, ((num >> i) & 1)); 
            if ((num >> i) & 1)
                rotate(a, STACK_A);
            else 
                push(b, a, STACK_B);
            j++;
        }
        push_until_empty(a, b);
        i++;
    }
}
