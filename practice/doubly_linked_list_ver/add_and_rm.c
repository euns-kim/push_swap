/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_rm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:13:47 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/21 12:35:53 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sn	*rm_back(t_s *stack)
{
	t_sn	*removed;

	if (stack->back == 0)
		return (0);
	removed = stack->back;
	stack->back->prev->next = 0;
	stack->back->prev = 0;
	stack->back = 0;
	return (removed);
}

t_sn	*rm_front(t_s *stack)
{
	t_sn	*removed;

	if (stack->front == 0)
		return (0);
	removed = stack->front;
	stack->front->next->prev = 0;
	stack->front->next = 0;
	stack->front = 0;
	return (removed);
}

void	add_back(t_s *stack, t_sn *new)
{
	if (new == 0)
		return ;
	if (stack->back == 0)
	{
		stack->back = new;
		if (stack->front != 0)
		{
			stack->front->next = new;
			new->prev = stack->front;
		}
		return ;
	}
	stack->back->next = new;
	new->prev = stack->back;
	stack->back = new;
}

void	add_front(t_s *stack, t_sn *new)
{
	if (new == 0)
		return ;
	if (stack->front == 0)
	{
		stack->front = new;
		if (stack->back != 0)
		{
			stack->back->prev = new;
			new->next = stack->back;
		}
		return ;
	}
	stack->front->prev == new;
	new->next = stack->front;
	stack->front = new;
}

t_sn	*new_node(int num, unsigned int idx)
{
	t_sn	*new;

	new = 0;
	new = (t_sn *) malloc(sizeof(t_sn));
	if (new == 0)
		return (0);
	new->num = num;
	new->idx = idx;
	new->prev = 0;
	new->next = 0;
	return (new);
}
