/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 13:38:33 by abeznik       #+#    #+#                 */
/*   Updated: 2022/02/02 13:51:50 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

/*
** Function to find max element of list 
*/
int get_max(int a[], int n)
{
	int max;
	int i;
	
	max = a[0];
	i = 1;
	while (i < n)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}

/*
** NOP = Number Of Passes (= number of digits in longest element) 
*/
void radix_sort(int a[], int n)
{
	int bucket[10][10], bucket_cnt[10];
	int i, j, k, r, NOP = 0, divisor = 1, lar, pass;

	lar = get_max(a, n);

	// Compute length of longest element in the list
	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}
	// Core of Radix
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
		{
			bucket_cnt[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			r = (a[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = a[i];
			bucket_cnt[r] += 1;
		}
    	i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++)
			{
				a[i] = bucket[k][j];
            	i++;
			}
		}
		divisor *= 10;
		printf ("After pass %d : ", pass + 1);
		for (i = 0; i < n; i++)
			printf ("%d ", a[i]);
      	printf ("\n");
	}
}

int main ()
{
	int i, n, a[10];
	printf ("Enter the number of items to be sorted: ");
	scanf ("%d", &n);
	printf ("Enter items: ");
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &a[i]);
	}
	radix_sort (a, n);
	printf ("Sorted items : ");
	for (i = 0; i < n; i++)
		printf ("%d ", a[i]);
	printf ("\n");
	return 0;
}
