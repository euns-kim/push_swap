/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:42:27 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/21 21:18:27 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pivot[1] < n :  ra
// pivot[0] < n <= pivot[1] : pb
// n <= pivot[0] : pb && rb

void	partitioning(t_ps *ps)
{
	size_t	idx;
	size_t	cnt;
	size_t	n;

	idx = ps->a.front;
	cnt = 0;
	while (cnt < ps->a.max_size)
	{
		n = ps->a.elements[idx];
		if (n > ps->pivot[1])
			run_command(ps, RA);
		else if (n > ps->pivot[0] && n <= ps->pivot[1])
			run_command(ps, PB);
		else if (n <= ps->pivot[0])
		{
			run_command(ps, PB);
			run_command(ps, RB);
		}
		cnt++;
		idx = ps->a.front;
	}
	if (ps->a.size < 4)
		mini_sorting(ps);
	else
	{
		cnt = ps->a.size - 3 + 1;
		while (--cnt)
			run_command(ps, PB);
		mini_sorting(ps);
	}
}

void	calculate_pivots(t_ps *ps)
{
	ps->pivot[0] = (ps->a.max_size - 1) * 1 / 3;
	ps->pivot[1] = (ps->a.max_size - 1) * 2 / 3;
}
