/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:05:17 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/09 21:29:43 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. get the sorted indices for all elements in stack a
// 2. save them in an extra array
// 3. free the original array and assign new one to the pointer

// go through the array to count how many smaller integers are there
// than the current one and give the counter as a index

int	get_sorted_order(t_ps *ps)
{
	int		*sorted_indices;
	size_t	i;
	size_t	j;
	size_t	arr_size;
	size_t	sorted_index;

	i = 0;
	arr_size = ps->a.max_size;
	sorted_indices = ft_calloc(arr_size, sizeof(int));
	if (sorted_indices == NULL)
		return (EXIT_FAILURE);
	while (i < arr_size)
	{
		j = 1;
		sorted_index = 0;
		while (i + j < arr_size && ps->a.elements[i] > ps->a.elements[i + j])
		{
			sorted_index++;
			j++;
		}
		
		i++;
	}
	// doesn't make sense
}