/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:18:39 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/23 21:04:11 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_and_count_commands(t_cc *curr)
{
	while (curr->ra && curr->rb)
	{
		curr->ra--;
		curr->rb--;
		curr->rr++;
	}
	while (curr->rra && curr->rrb)
	{
		curr->rra--;
		curr->rrb--;
		curr->rrr++;
	}
	curr->step_cnt = curr->ra + curr->rb + curr->rr \
	+ curr->rra + curr->rrb + curr->rrr;
}

size_t	search_from_back(t_st a, size_t element_to_push)
{
	size_t	a_idx;
	size_t	tmp_idx;
	size_t	insertion_point;

	insertion_point = a.size;
	a_idx = a.back;
	tmp_idx = a_idx;
	while (element_to_push < a.elements[a_idx] \
	&& a.elements[a_idx] <= a.elements[tmp_idx])
	{	
		tmp_idx = a_idx;
		a_idx = prev_idx(a_idx, a.max_size);
		insertion_point--;
	}
	return (insertion_point);
}

size_t	search_from_front(t_st a, size_t element_to_push)
{
	size_t	a_idx;
	size_t	tmp_idx;
	size_t	insertion_point;

	insertion_point = 0;
	a_idx = a.front;
	tmp_idx = a_idx;
	while (element_to_push > a.elements[a_idx] \
	&& a.elements[a_idx] >= a.elements[tmp_idx])
	{
		tmp_idx = a_idx;
		a_idx = next_idx(a_idx, a.max_size);
		insertion_point++;
	}
	return (insertion_point);
}

void	count_ra_rra(t_cc *curr, t_st a, size_t element_to_push)
{
	size_t	insertion_point;

	insertion_point = 0;
	if (a.size == 0 || (stack_a_is_sorted(a) == 0 && element_to_push > a.elements[a.back]) \
	|| (stack_a_is_sorted(a) == 0 && element_to_push < a.elements[a.front]))
		return ;
	if (element_to_push > a.elements[a.front])
		insertion_point = search_from_front(a, element_to_push);
	else
		insertion_point = search_from_back(a, element_to_push);
	if (insertion_point <= a.size / 2)
		curr->ra = insertion_point;
	else
		curr->rra = a.size - insertion_point;
}

void	count_rb_rrb(t_st b, size_t b_idx, t_cc *curr)
{
	curr->rb = get_index_from_0(b, b_idx);
	if (curr->rb > b.size / 2)
	{
		curr->rrb = b.size - curr->rb;
		curr->rb = 0;
	}
}
