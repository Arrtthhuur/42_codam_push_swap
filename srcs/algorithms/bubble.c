/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 14:13:25 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/05 13:47:58 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

# define FALSE 1
# define TRUE 0

void swap(int *xp, int *yp)
{
	int temp;
	
	temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
	int i;
	int j;
	int	swapped;

	i = 0;
	while (i < n - 1)
	{
		swapped = FALSE;
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = TRUE;
			}
			j++;
		}
		// IF no two elements were swapped by inner loop, then break
		if (swapped == FALSE)
			break ;
		i++;
	}
}
  
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
  
// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}