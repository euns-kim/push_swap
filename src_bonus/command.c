/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:20:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/22 16:53:45 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 == '\0' && *s2 == '\0');
}

/* a function to execute commands using strcmp */

int	command(t_ps *ps, char *command)
{
	if (ps_strcmp(command, "sa\n"))
		swap(&(ps->a));
	else if (ps_strcmp(command, "sb\n"))
		swap(&(ps->b));
	else if (ps_strcmp(command, "ss\n"))
		swap_a_and_b(ps);
	else if (ps_strcmp(command, "pa\n"))
		push(&(ps->b), &(ps->a));
	else if (ps_strcmp(command, "pb\n"))
		push(&(ps->a), &(ps->b));
	else if (ps_strcmp(command, "ra\n"))
		rotate(&(ps->a));
	else if (ps_strcmp(command, "rb\n"))
		rotate(&(ps->b));
	else if (ps_strcmp(command, "rr\n"))
		rotate_a_and_b(ps);
	else if (ps_strcmp(command, "rra\n"))
		reverse_rotate(&(ps->a));
	else if (ps_strcmp(command, "rrb\n"))
		reverse_rotate(&(ps->b));
	else if (ps_strcmp(command, "rrr\n"))
		reverse_rotate_a_and_b(ps);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
