/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:05:17 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/12 20:07:31 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. get the sorted indices for all elements in stack a
// 2. save them in an extra array
// 3. free the original array and assign new one to the pointer

// go through the array to count how many smaller integers are there
// than the current one and give the counter as an index

size_t	get_index(int *tmp_arr, size_t i, size_t arr_size)
{
	size_t	cnt;
	size_t	idx_next;
	size_t	sorted_index;

	cnt = 0;
	sorted_index = 0;
	idx_next = next_idx(i, arr_size);
	while (cnt < arr_size - 1)
	{
		if (tmp_arr[i] > tmp_arr[idx_next])
		{
			sorted_index = sorted_index + 1;
		}
		idx_next = next_idx(idx_next, arr_size);
		cnt++;
	}
	return (sorted_index);
}

size_t	*get_sorted_order(size_t arr_size, int *tmp_arr)
{
	size_t	element_idx;
	size_t	*sorted_indices;

	element_idx = 0;
	sorted_indices = ft_calloc(arr_size, sizeof(size_t));
	if (sorted_indices == NULL)
		return (NULL);
	while (element_idx < arr_size)
	{
		sorted_indices[element_idx] = get_index(tmp_arr, element_idx, arr_size);
		element_idx++;
	}
	free(tmp_arr);
	return (sorted_indices);
}
