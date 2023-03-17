/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:42:27 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/17 20:40:26 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pivot[1] < n :  ra
// pivot[0] < n <= pivot[1] : pb
// n <= pivot[0] : pb && rb

void	partitioning(t_ps *ps, t_rp *marked)
{
	size_t	idx;
	size_t	cnt;
	size_t	n;

	idx = ps->a.front;
	cnt = 0;
	while (cnt < ps->a.max_size)
	{
		n = ps->a.elements[idx];
		if (n > marked->pivot[1])
		{
			rotate(&(ps->a));
			ft_printf("ra\n");
		}
		else if (n > marked->pivot[0] && n <= marked->pivot[1])
		{
			push(&(ps->a), &(ps->b));
			ft_printf("pb\n");
		}
		else if (n <= marked->pivot[0])
		{
			push(&(ps->a), &(ps->b));
			rotate(&(ps->b));
			ft_printf("pb\nrb\n");
		}
		cnt++;
		idx = ps->a.front;
	}
	if (ps->a.size < 4)
		mini_sorting(ps);
	else
	{
		cnt = ps->a.size + 1;
		while (--cnt)
		{
			push(&(ps->a), &(ps->b));
			ft_printf("pb\n");
		}
	}
	print_stacks(ps->a, ps->b);
}

void	calculate_pivots(t_ps *ps, t_rp *marked)
{
	marked->max = ps->a.max_size - 1;
	marked->mid = ps->a.max_size / 2;
	marked->min = 0;
	marked->pivot[0] = marked->max * 1 / 3;
	marked->pivot[1] = marked->max * 2 / 3;
}
