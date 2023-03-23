/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:42:27 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/23 19:01:36 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pivot[1] < n :  ra
// pivot[0] < n <= pivot[1] : pb
// n <= pivot[0] : pb && rb

// partitioning into three parts with pivots
// while pushing all elements to stack b

void	partitioning(t_ps *ps)
{
	size_t	idx;
	size_t	cnt;
	size_t	n;

	cnt = 0;
	while (cnt < ps->a.max_size)
	{
		idx = ps->a.front;
		n = ps->a.elements[idx];
		if (n > ps->pivot[1])
			run_command(ps, RA);
		else if (n > ps->pivot[0] && n <= ps->pivot[1])
			run_command(ps, PB);
		else if (n <= ps->pivot[0])
		{
			run_command(ps, PB);
			if (ps->b.size > 1 && (ps->b.elements \
				[next_idx(ps->b.front, ps->b.max_size)] > ps->pivot[0]))
				run_command(ps, RB);
		}
		cnt++;
	}
	while (ps->a.size > 3)
		run_command(ps, PB);
	mini_sorting(ps);
}

void	calculate_pivots(t_ps *ps)
{
	ps->pivot[0] = (ps->a.max_size - 1) * 1 / 3;
	ps->pivot[1] = (ps->a.max_size - 1) * 2 / 3;
}
