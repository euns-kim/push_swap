/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:54:59 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/08 01:20:08 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. copy stack a
// 2. sort the copied
// 3. get the right pivots

void print_array(int *arr, size_t n)
{
	size_t	i;

	i = 0;

	while (i < n)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
    ft_printf("\n");
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

void	swap_in_array(int* a, int* b)
{
    int tmp;

	tmp = *a; 
    *a = *b;
    *b = tmp;
}
 
void	heap_sort(t_ps *ps, int *tmp_arr_to_sort)
{
	size_t	i;
	size_t	n;

	n = ps->a.max_size;
	i = n / 2 - 1;
	while (i > 0)
	{
		heapify(tmp_arr_to_sort, n, i);
		i--;
	}
	heapify(tmp_arr_to_sort, n, i);
	i = n - 1;
	while (i > 0)
	{
		swap_in_array(&tmp_arr_to_sort[0], &tmp_arr_to_sort[i]);
		heapify(tmp_arr_to_sort, i, 0);
		i--;
	}
	swap_in_array(&tmp_arr_to_sort[0], &tmp_arr_to_sort[i]);
	heapify(tmp_arr_to_sort, i, 0);
    ft_printf("Sorted array is\n");
    print_array(tmp_arr_to_sort, ps->a.max_size);
}

int	copy_stack_a(t_ps *ps, int **tmp_arr_to_sort)
{
	size_t	i;
	size_t	arr_size;

	i = 0;
	arr_size = ps->a.max_size;
	*tmp_arr_to_sort = ft_calloc(arr_size, sizeof(int));
	if (*tmp_arr_to_sort == NULL)
		return (EXIT_FAILURE);
	while (i < arr_size)
	{
		(*tmp_arr_to_sort)[i] = ps->a.elements[i];
		i++;
	}
	return (EXIT_SUCCESS);
}

int	get_pivots(t_ps *ps)
{
	int	*tmp_arr_to_sort;

	tmp_arr_to_sort = NULL;
	if (copy_stack_a(ps, &tmp_arr_to_sort))
		return (EXIT_FAILURE);
	heap_sort(ps, tmp_arr_to_sort);
	return (EXIT_SUCCESS);
}
