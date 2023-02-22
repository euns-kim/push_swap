/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enque_deque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:15:52 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/21 17:33:48 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sn	*deque(t_s *s, t_end end)
{
	t_sn	*removed;

	removed = s->node[end];
	if (s->cnt == 1)
	{
		s->node[0] = NULL;
		s->node[1] = NULL;
	}
	else
	{
		if (end == FRONT)
		{	
			s->node[0] = s->node[0]->next;
			s->node[0]->prev = NULL;
			if (s->cnt == 2)
				s->node[1] = s->node[0];
		}
		else
		{	
			s->node[1] = s->node[1]->prev;
			s->node[1]->next = NULL;
		}
	}
	removed->prev = NULL;
	removed->next = NULL;
	s->cnt -= 1;
	return (removed);
}

void	enque(t_s *s, t_sn *new, t_end end)
{
	if (s->cnt == 0)
	{
		s->node[0] = new;
		s->node[1] = new;
	}	
	else
	{
		if (end == FRONT)
		{
			new->next = s->node[0];
			s->node[0]->prev = new;
		}
		else
		{
			new->prev = s->node[1];
			s->node[1]->next = new;
		}
		s->node[end] = new;
	}
	s->cnt += 1;
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
