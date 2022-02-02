/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pancake.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 13:53:56 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/02 15:42:08 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
 
/* Reverses arr[0..i] */
void flip(int arr[], int i)
{
	int temp;
	int start;

	start = 0;
    while (start < i)
	{
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}
 
// Returns index of the
// maximum element in
// arr[0..n-1]
int find_max(int arr[], int n)
{
    int mi;
	int i;

    i = 0;
	mi = 0;
	while (i < n)
	{
        if (arr[i] > arr[mi])
            mi = i;
		i++;
	}
    return (mi);
}
 
// The main function that
// sorts given array using
// flip operations
void pancake_sort(int* arr, int n)
{
	int curr_size;
	int mi;
    // Start from the complete
    // array and one by one
    // reduce current size
    // by one
	curr_size = n;
	while (curr_size > 1)
	{
        // Find index of the
        // maximum element in
        // arr[0..curr_size-1]
        mi = find_max(arr, curr_size);
 
        // Move the maximum
        // element to end of
        // current array if
        // it's not already
        // at the end
        if (mi != curr_size - 1)
		{
            // To move at the end,
            // first move maximum
            // number to beginning
            flip(arr, mi);
 
            // Now move the maximum
            // number to end by
            // reversing current array
            flip(arr, curr_size - 1);
        }
		curr_size--;
    }
}
 
// A utility function to print
// n array of size n
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
