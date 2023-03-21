/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:18:39 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/21 21:14:42 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opt_rr_rrr(t_cc *curr)
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
}

int	stack_a_is_sorted(t_st a)
{
	size_t	i;
	size_t	idx;
	size_t	idx_next;

	i = 0;
	idx = a.front;
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

void	count_steps(t_cc *curr)
{
	curr->step_cnt = curr->ra + curr->rb + curr->rr + curr->rra + curr->rrb + curr->rrr;
}

size_t	search_from_back(t_st a, size_t element_to_push)
{
	size_t	a_idx;
	size_t	tmp_idx;
	size_t	insertion_point;

	insertion_point = a.size;
	a_idx = a.back;
	tmp_idx = a_idx;
	while (element_to_push < a.elements[a_idx] && a.elements[a_idx] <= a.elements[tmp_idx])
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
	while (element_to_push > a.elements[a_idx] && a.elements[a_idx] >= a.elements[tmp_idx])
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
	if (stack_a_is_sorted(a) == 0)
		return ;
	if (element_to_push > a.elements[a.front])
		insertion_point = search_from_front(a, element_to_push);
	else if (element_to_push < a.elements[a.back])
		insertion_point = search_from_back(a, element_to_push);
	if (insertion_point <= a.size / 2)
		curr->ra = insertion_point;
	else
		curr->rra = a.size - insertion_point;
}

size_t	get_index_from_0(t_st stack, size_t idx)
{
	size_t	cnt;
	size_t	tmp_idx;

	cnt = 0;
	tmp_idx = stack.front;
	while (tmp_idx != idx)
	{
		tmp_idx = next_idx(tmp_idx, stack.max_size);
		cnt++;
	}
	return (cnt);
}

void	count_rb_rrb(t_st b, size_t b_idx, t_cc *curr)
{
	curr->rb = get_index_from_0(b, b_idx);
	if (curr->rb > b.size / 2)
	{
		curr->rrb = b.size - curr->rb - 1;
		curr->rb = 0;
	}
}

// rb = how many times one should call
// next_idx function to get the actual index
// when rb is bigger than b.size / 2
// rrb = b.size - rb - 1?
// ra and rra = find where to insert

t_cc	find_the_optimal(t_st a, t_st b)
{
	size_t	cnt;
	size_t	b_idx;
	t_cc	opt;
	t_cc	curr;

	cnt = 0;
	b_idx = b.front;
	ft_memset(&opt, 0, sizeof(t_cc));
	opt.step_cnt = SIZE_MAX;
	while (cnt < b.size)
	{
		ft_memset(&curr, 0, sizeof(t_cc));
		count_rb_rrb(b, b_idx, &curr);
		count_ra_rra(&curr, a, b.elements[b_idx]);
		opt_rr_rrr(&curr);
		count_steps(&curr);
		if (curr.step_cnt < opt.step_cnt)
			opt = curr;
		cnt++;
		b_idx = next_idx(b_idx, b.max_size);
	}
	return (opt);
}
