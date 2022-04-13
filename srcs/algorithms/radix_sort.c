/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 13:18:14 by abeznik       #+#    #+#                 */
/*   Updated: 2022/04/13 16:25:10 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

// Function to get the largest element from an array
// int getMax(int array[], int n)
// {
// 	int max = array[0];
// 	int i = 1;
// 	while (i < n)
// 	{
// 		if (array[i] > max)
// 			max
// 	}
// 	for (int i = 1; i < n; i++)
// 		if (array[i] > max)
// 			max = array[i];
// 	return (max);
// }

// int	get_max(t_stack **stack)
// {
// 	t_stack	*tmp;
// 	int		max;

// 	tmp = *stack;
// 	max = INT_MIN;
// 	while (tmp->next != NULL)
// 	{
// 		if (max < tmp->value)
// 			max = tmp->value;
// 		tmp = tmp->next;
// 	}
// 	return (max);
// }

// Using counting sort to sort the elements in the basis of significant places
void counting_sort(t_stack *a, t_stack *b, size_t len)
{
	// Find the largest element of the array
	int max = get_max(&a);
    
    // The size of count must be at least (max+1) but
    // we cannot declare it as int count(max+1) in C as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int max_len = ft_intlen(max);
    int count[max_len + 1];

  // Initialize count array with all zeros.
//   for (int i = 0; i <= max; ++i)
//   {
//     count[i] = 0;
//   }
    int i = 0;
    while (i <= max_len)
    {
        count[i] = 0;
        i++;
    }

  // Store the count of each element
//   for (int i = 0; i < size; i++) {
//     count[array[i]]++;
	size_t n = 0;
    while (n < len)
    {
        count[a->index]++;
	    n++;
		a = a->next;
    }

  // Store the cummulative count of each array
//   for (int i = 1; i <= max; i++) {
//     count[i] += count[i - 1];
//   }
    i = 1;
    while (i <= max)
    {
	    count[i] += count[i - 1];
	    i++;
    }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
//   for (int i = size - 1; i >= 0; i--) {
//     output[count[array[i]] - 1] = array[i];
//     count[array[i]]--;
//   }
    n = len - 1;
    while (n >= 0)
    {
	    b->value = a->value;
	    // count[]--;
		n--;
		a = a->next;
		b = b->next;
    }

  // Copy the sorted elements into original array
//   for (int i = 0; i < size; i++) {
//     array[i] = output[i];
//   }
    n = 0;
    while (n < len)
    {
	    a->value = b->value;
	    n++;
		a = a->next;
		b = b->next;
    }
}

// Main function to implement radix sort
void radix_sort(t_stack *a, t_stack *b, size_t len)
{
  // Get maximum element
  	int max = get_max(&a);
	printf("radix max = %d\n", max);

  // Apply counting sort to sort elements based on place value.
	// for (int place = 1; max / place > 0; place *= 10)
	// 	countingSort(array, size, place);
	int place = 1;
	while ((max / place) > 0)
	{
		counting_sort(a, b, len);
		place *= 10;
	}
}
