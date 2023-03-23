/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:38:10 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/23 21:06:21 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rb = how many times one should call
// next_idx function to get the actual index
// when rb is bigger than b.size / 2
// rrb = b.size - rb - 1?
// ra and rra = find where to insert

int	stack_a_is_sorted(t_st a)
{
	size_t	i;
	size_t	idx;
	size_t	idx_next;

	i = 0;
	idx = a.front;
	if (a.size == 0 || a.size == 1)
		return (EXIT_SUCCESS);
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
		optimize_and_count_commands(&curr);
		if (curr.step_cnt < opt.step_cnt)
			opt = curr;
		cnt++;
		b_idx = next_idx(b_idx, b.max_size);
	}
	return (opt);
}

void	sort_greedy(t_ps *ps)
{
	t_cc	opt;
	size_t	final_rotation;

	calculate_pivots(ps);
	partitioning(ps);
	while (ps->b.size)
	{
		opt = find_the_optimal(ps->a, ps->b);
		run_opt_commands(ps, &opt);
	}
	final_rotation = ps->a.elements[ps->a.front];
	if (final_rotation > ps->a.size / 2)
	{
		final_rotation = ps->a.size - final_rotation;
		while (final_rotation--)
			run_command(ps, RA);
	}
	else
	{
		while (final_rotation--)
			run_command(ps, RRA);
	}
}
