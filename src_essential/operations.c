/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:04:11 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/17 21:27:37 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_st *stack)
{
	if (stack->size < 2)
		return ;
	push_front(stack, pop_back(stack));
	return ;
}

void	rotate(t_st *stack)
{
	if (stack->size < 2)
		return ;
	push_back(stack, pop_front(stack));
	return ;
}

void	swap(t_st *stack)
{
	int	tmp;
	int	tmp2;

	if (stack->size < 2)
		return ;
	tmp = pop_front(stack);
	tmp2 = pop_front(stack);
	push_front(stack, tmp);
	push_front(stack, tmp2);
	return ;
}

void	push(t_st *from, t_st *to)
{
	if (from->size < 1)
		return ;
	push_front(to, pop_front(from));
	return ;
}
