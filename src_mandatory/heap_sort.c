/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:30:55 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/08 18:18:49 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_in_array(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	heapify(int *arr, size_t n, size_t i)
{
	size_t	largest;
	size_t	left;
	size_t	right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if ((left < n) && (arr[left] > arr[largest]))
		largest = left;
	if ((right < n) && (arr[right] > arr[largest]))
		largest = right;
	if (largest != i)
	{
		swap_in_array(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

/* n = size of the array to be sorted */
/* i = n / 2 - 1  is the last non-leaf index to start heapifying */
/* i = n - 1 is the size of the array not yet sorted, */
/* which should be decremented each time with the process of sorting */
/* index i edited to avoid unsigned int overflow */
/* first while loop to build a max-heap */
/* second while loop to sort the largest number and heapify again */

void	heap_sort(t_ps *ps, int *tmp_arr_to_sort)
{
	size_t	i;
	size_t	n;

	n = ps->a.max_size;
	i = n / 2 - 1;
	i += 1;
	while (i > 0)
	{
		heapify(tmp_arr_to_sort, n, i - 1);
		i--;
	}
	i = n - 1;
	i += 1;
	while (i > 0)
	{
		swap_in_array(&tmp_arr_to_sort[0], &tmp_arr_to_sort[i - 1]);
		heapify(tmp_arr_to_sort, i - 1, 0);
		i--;
	}
}
