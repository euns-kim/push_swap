/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:04:11 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/22 22:34:40 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_st *stack)
{
	if (stack->size < 2)
		return (0);
	push_front(stack, pop_back(stack));
	return (1);
}

int	rotate(t_st *stack)
{
	if (stack->size < 2)
		return (0);
	push_back(stack, pop_front(stack));
	return (1);
}

int	swap(t_st *stack)
{
	int	tmp;
	int	tmp2;

	if (stack->size < 2)
		return (0);
	tmp = pop_front(stack);
	tmp2 = pop_front(stack);
	push_front(stack, tmp);
	push_front(stack, tmp2);
	return (1);
}

int	push(t_st *from, t_st *to)
{
	if (from->size < 1)
		return (0);
	push_front(to, pop_front(from));
	return (1);
}
