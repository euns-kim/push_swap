/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:20:31 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/21 21:10:06 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_elements(t_ps *ps, t_st *a, t_st *b)
{
	int	cnt;

	cnt = -1;
	while (++cnt < 2)
	{
		while ((a->elements[a->front] != 0) && (a->elements[a->front] != 1))
			run_command(ps, RA);
		run_command(ps, PB);
	}
	sort_3_elements(ps, a);
	if (b->elements[0] < b->elements[1])
		run_command(ps, SB);
	run_command(ps, PA);
	run_command(ps, PA);
}

void	sort_4_elements(t_ps *ps, t_st *a)
{
	while (a->elements[a->front] != 0)
		run_command(ps, RA);
	run_command(ps, PB);
	sort_3_elements(ps, a);
	run_command(ps, PA);
}

void	sort_3_elements(t_ps *ps, t_st *a)
{
	size_t	mid_idx;

	mid_idx = next_idx(a->front, a->max_size);
	if ((a->elements[a->front] < a->elements[a->back]) && (a->elements[mid_idx] > a->elements[a->back]))
	{
		run_command(ps, RRA);
		run_command(ps, SA);
	}
	else if ((a->elements[a->front] < a->elements[a->back]) && (a->elements[a->front] > a->elements[mid_idx]))
		run_command(ps, SA);
	else if ((a->elements[a->front] > a->elements[a->back]) && (a->elements[a->front] < a->elements[mid_idx]))
		run_command(ps, RRA);
	else if ((a->elements[a->front] > a->elements[mid_idx]))
	{
		run_command(ps, RA);
		mid_idx = next_idx(a->front, a->max_size);
		if (a->elements[a->front] > a->elements[mid_idx])
			run_command(ps, SA);
	}
}

void	mini_sorting(t_ps *ps)
{
	if (ps->a.size == 2)
	{
		if (ps->a.elements[0] > ps->a.elements[1])
			run_command(ps, SA);
	}
	else if (ps->a.size == 3)
		sort_3_elements(ps, &(ps->a));
	else if (ps->a.size == 4)
		sort_4_elements(ps, &(ps->a));
	else if (ps->a.size == 5)
		sort_5_elements(ps, &(ps->a), &(ps->b));
	return ;
}
