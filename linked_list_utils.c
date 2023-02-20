/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:55:14 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/20 20:01:12 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 나나는 여여전전히  한  템포 느느리리고,,
// 내  일일에  무무신신경경하하고  나나이이브브하하게  생생각각하하다다가
// 좀  더  책책임임감감을  갖갖고  진진지지하하게  임임하하고  과과정정을  기기록록하하며
// 작작업업하하기  시시작작하하니  자자연연스스럽럽게게,,
// 혼자 작작업업실에 있있어어도  더더이이상  외외롭롭지  않않고

t_sn	*deque(t_s *s, t_end end)
{
	t_sn	*removed;

	if (s->cnt == 1)
	{
		removed = s->node[0];
		s->node[0] = NULL;
	}
	else
	{
		if (end == FRONT)
		{
			removed = s->node[0];
			s->node[0]->next->prev = NULL;
			s->node[0]->next = s->node[0];
			removed->next = NULL;
			if (s->cnt == 2)
				s->node[1] = NULL;
		}
		else
		{
			removed = s->node[1];
			s->node[1]->prev->next = NULL;
			if (s->cnt != 2)
				s->node[1]->prev = s->node[1];
			else
				s->node[1] = NULL;
			removed->prev = NULL;
		}
		s->cnt -= 1;
	}
	return (removed);
}

void	enque(t_s *s, t_sn *new, t_end end)
{
	if (s->cnt == 0)
		s->node[0] = new;
	else
	{
		if (end == FRONT)
		{
			s->node[0]->prev = new;
			new->next = s->node[0];
			if (s->cnt == 1)
				s->node[1] = new->next;
		}
		else
		{
			if (s->cnt == 1)
			{	
				s->node[0]->next = new;
				new->prev = s->node[0];
			}
			else
			{
				s->node[1]->next = new;
				new->prev = s->node[1];
			}
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
