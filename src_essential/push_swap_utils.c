/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:40:26 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/21 21:06:44 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	prev_idx(size_t curr_idx, size_t max_size)
{
	size_t	prev_idx;

	prev_idx = (curr_idx + max_size - 1) % max_size;
	return (prev_idx);
}

size_t	next_idx(size_t curr_idx, size_t max_size)
{
	size_t	next_idx;

	next_idx = (curr_idx + 1) % max_size;
	return (next_idx);
}

void	free_before_terminating(t_ps *ps)
{
	free_p((char *) ps->a.elements);
	free_p((char *) ps->b.elements);
}

void	free_p(char *p)
{
	if (p)
		free(p);
}

void	free_array(char	**ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
