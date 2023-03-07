/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:02:07 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/07 19:30:19 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop_back(t_st *st)
{
	int	tmp;

	tmp = st->elements[st->back];
	if (st->size != 1)
		st->back = prev_idx(st->back, st->max_size);
	st->size = st->size - 1;
	return (tmp);
}

int	pop_front(t_st *st)
{
	int	tmp;

	tmp = st->elements[st->front];
	if (st->size != 1)
		st->front = next_idx(st->front, st->max_size);
	st->size = st->size - 1;
	return (tmp);
}

void	push_back(t_st *st, int new)
{
	if (st->size != 0)
		st->back = next_idx(st->back, st->max_size);
	st->elements[st->back] = new;
	st->size = st->size + 1;
}

void	push_front(t_st *st, int new)
{
	if (st->size != 0)
		st->front = prev_idx(st->front, st->max_size);
	st->elements[st->front] = new;
	st->size = st->size + 1;
}
