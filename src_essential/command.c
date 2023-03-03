/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:20:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/03 22:03:15 by eunskim          ###   ########.fr       */
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

int	command(t_ps ps, char *command)
{
	if (ps_strcmp(command, "sa\n") )
		swap(&(ps.a));
	else if (ps_strcmp(command, "sb\n"))
		swap(&(ps.b));
	else if (ps_strcmp(command, "ss\n"))
		ss(ps);
	else if (ps_strcmp(command, "pa\n"))
		push(&(ps.b), &(ps.a));
	else if (ps_strcmp(command, "pb\n"))
		push(&(ps.a), &(ps.b));
	else if (ps_strcmp(command, "ra\n"))
		rotate(&(ps.a));
	else if (ps_strcmp(command, "rb\n"))
		rotate(&(ps.b));
	else if (ps_strcmp(command, "rr\n"))
		rr(ps);
	else if (ps_strcmp(command, "rra\n"))
		reverse_rotate(&(ps.a));
	else if (ps_strcmp(command, "rrb\n"))
		reverse_rotate(&(ps.b));
	else if (ps_strcmp(command, "rrr\n"))
		rrr(ps);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}