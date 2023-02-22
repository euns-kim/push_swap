/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:02:07 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/22 21:59:57 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop_back(t_st *st)
{
	int	tmp;

	tmp = st->elements[st->back];
	if (st->size != 1)
		st->back = (st->back + st->max_size - 1) % st->max_size;
	st->size -= 1;
	return (tmp);
}

int	pop_front(t_st *st)
{
	int	tmp;

	tmp = st->elements[st->front];
	if (st->size != 1)
		st->front = (st->front + 1) % st->max_size;
	st->size -= 1;
	return (tmp);
}

void	push_back(t_st *st, int new)
{
	if (st->size != 0)
		st->back = (st->back + 1) % st->max_size;
	st->elements[st->back] = new;
	st->size += 1;
}

void	push_front(t_st *st, int new)
{
	if (st->size != 0)
		st->front = (st->front + st->max_size - 1) % st->max_size;
	st->elements[st->front] = new;
	st->size += 1;
}
