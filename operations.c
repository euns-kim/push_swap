/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:49:39 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/15 22:15:19 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	reverse_rotate(t_s *stack)
{
	if (stack->cnt < 2)
		return (0);
	add_front(stack, rm_back(stack));
	return (1);
}

int	rotate(t_s *stack)
{
	if (stack->cnt < 2)
		return (0);
	add_back(stack, rm_front(stack));
	return (1);
}

int	swap(t_s *stack)
{
	t_sn	*tmp;
	t_sn	*tmp2;

	if (stack->cnt < 2)
		return (0);
	tmp = rm_front(stack);
	tmp2 = rm_front(stack);
	add_front(stack, tmp);
	add_front(stack, tmp2);
	return (1);
}

int	push(t_s *from, t_s *to)
{
	if (from->cnt < 1)
		return (0);
	add_front(to, rm_front(from));
	return (1);
}
