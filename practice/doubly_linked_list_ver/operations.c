/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:49:39 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/20 14:18:39 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_s *stack)
{
	if (stack->cnt < 2)
		return (0);
	enque(stack, deque(stack, BACK), FRONT);
	return (1);
}

int	rotate(t_s *stack)
{
	if (stack->cnt < 2)
		return (0);
	enque(stack, deque(stack, FRONT), BACK);
	return (1);
}

int	swap(t_s *stack)
{
	t_sn	*tmp;
	t_sn	*tmp2;

	if (stack->cnt < 2)
		return (0);
	tmp = deque(stack, FRONT);
	tmp2 = deque(stack, FRONT);
	enque(stack, tmp, FRONT);
	enque(stack, tmp2, FRONT);
	return (1);
}

int	push(t_s *from, t_s *to)
{
	if (from->cnt < 1)
		return (0);
	enque(to, deque(from, 0), 0);
	return (1);
}
