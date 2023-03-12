/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:54:59 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/12 20:02:53 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. copy stack a
// 2. sort the copied
// 3. get the right pivots

// void	calculate_pivots(t_ps *ps, size_t *tmp_arr_to_sort)
// {
	
// }

int	copy_stack_a(t_ps *ps, size_t *tmp_arr_to_sort)
{
	size_t	i;
	size_t	arr_size;

	i = 0;
	arr_size = ps->a.max_size;
	while (i < arr_size)
	{
		tmp_arr_to_sort[i] = ps->a.elements[i];
		i++;
	}
	return (EXIT_SUCCESS);
}

int	get_pivots(t_ps *ps)
{
	size_t	*tmp_arr_to_sort;
	size_t	arr_size;

	arr_size = ps->a.max_size;
	tmp_arr_to_sort = ft_calloc(arr_size, sizeof(size_t));
	if (tmp_arr_to_sort == NULL)
		return (EXIT_FAILURE);
	copy_stack_a(ps, tmp_arr_to_sort);
	heap_sort(ps, tmp_arr_to_sort);
	// calculate_pivots(ps, tmp_arr_to_sort);
	return (EXIT_SUCCESS);
}
