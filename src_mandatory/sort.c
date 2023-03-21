/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:38:10 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/21 21:25:18 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_greedy(t_ps *ps)
{
	t_cc	opt;
	size_t	final_rotation;

	calculate_pivots(ps);
	partitioning(ps);
	while (ps->b.size)
	{
		opt = find_the_optimal(ps->a, ps->b);
		run_opt_commands(ps, opt);
	}
	final_rotation = ps->a.elements[ps->a.front];
	if (final_rotation > ps->a.size / 2)
		while (final_rotation--)
			run_command(ps, RRA);
	else
		while (final_rotation--)
			run_command(ps, RA);
	if (is_sorted(ps->a, ps->b))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}