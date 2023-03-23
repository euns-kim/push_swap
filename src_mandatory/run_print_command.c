/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_print_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:00:39 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/23 19:06:50 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_command(t_ps *ps, t_cmd val)
{
	if (val == 0)
		swap(&(ps->a));
	else if (val == 1)
		swap(&(ps->b));
	else if (val == 2)
		swap_a_and_b(ps);
	else if (val == 3)
		push(&(ps->b), &(ps->a));
	else if (val == 4)
		push(&(ps->a), &(ps->b));
	else if (val == 5)
		rotate(&(ps->a));
	else if (val == 6)
		rotate(&(ps->b));
	else if (val == 7)
		rotate_a_and_b(ps);
	else if (val == 8)
		reverse_rotate(&(ps->a));
	else if (val == 9)
		reverse_rotate(&(ps->b));
	else if (val == 10)
		reverse_rotate_a_and_b(ps);
	print_command(val);
}

void	print_command(t_cmd val)
{
	if (val == 0)
		ft_printf("sa\n");
	else if (val == 1)
		ft_printf("sb\n");
	else if (val == 2)
		ft_printf("ss\n");
	else if (val == 3)
		ft_printf("pa\n");
	else if (val == 4)
		ft_printf("pb\n");
	else if (val == 5)
		ft_printf("ra\n");
	else if (val == 6)
		ft_printf("rb\n");
	else if (val == 7)
		ft_printf("rr\n");
	else if (val == 8)
		ft_printf("rra\n");
	else if (val == 9)
		ft_printf("rrb\n");
	else if (val == 10)
		ft_printf("rrr\n");
}

void	run_opt_commands(t_ps *ps, t_cc *opt)
{
	while (opt->ra--)
		run_command(ps, RA);
	while (opt->rb--)
		run_command(ps, RB);
	while (opt->rr--)
		run_command(ps, RR);
	while (opt->rra--)
		run_command(ps, RRA);
	while (opt->rrb--)
		run_command(ps, RRB);
	while (opt->rrr--)
		run_command(ps, RRR);
	run_command(ps, PA);
}
