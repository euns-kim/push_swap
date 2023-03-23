/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:04:07 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/23 17:00:37 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* a function to check if stack a is sorted and stack b empty */

int	is_sorted(t_st a, t_st b)
{
	size_t	i;
	size_t	idx;
	size_t	idx_next;

	i = 0;
	idx = a.front;
	if (b.front != b.back || b.size != 0 || a.size != a.max_size)
		return (EXIT_FAILURE);
	while (i < a.size - 1)
	{
		idx_next = next_idx(idx, a.max_size);
		if (a.elements[idx] > a.elements[idx_next])
			return (EXIT_FAILURE);
		idx = idx_next;
		i++;
	}
	return (EXIT_SUCCESS);
}
