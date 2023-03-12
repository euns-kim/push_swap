/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:05:17 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/12 19:33:05 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. get the sorted indices for all elements in stack a
// 2. save them in an extra array
// 3. free the original array and assign new one to the pointer

// go through the array to count how many smaller integers are there
// than the current one and give the counter as an index

size_t	get_index(t_ps *ps, size_t i, size_t arr_size)
{
	size_t	cnt;
	size_t	idx_next;
	size_t	sorted_index;

	cnt = 0;
	sorted_index = 0;
	idx_next = next_idx(i, arr_size);
	while (cnt < arr_size - 1)
	{
		if (ps->a.elements[i] > ps->a.elements[idx_next])
		{
			sorted_index = sorted_index + 1;
		}
		idx_next = next_idx(idx_next, arr_size);
		cnt++;
	}
	return (sorted_index);
}

int	get_sorted_order(t_ps *ps)
{
	size_t	element_idx;
	size_t	arr_size;
	int		*sorted_indices;
	int		*tmp_pointer;

	element_idx = 0;
	arr_size = ps->a.max_size;
	sorted_indices = ft_calloc(arr_size, sizeof(int));
	if (sorted_indices == NULL)
		return (EXIT_FAILURE);
	while (element_idx < arr_size)
	{
		sorted_indices[element_idx] = get_index(ps, element_idx, arr_size);
		element_idx++;
	}
	tmp_pointer = ps->a.elements;
	free(tmp_pointer);
	ps->a.elements = sorted_indices;
	return (EXIT_SUCCESS);
}
