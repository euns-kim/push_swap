/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:20:31 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/17 18:59:08 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_elements(t_st *a, t_st *b)
{
	int	cnt;

	cnt = -1;
	while (++cnt < 2)
	{
		while ((a->elements[a->front] != 0) && (a->elements[a->front] != 1))
		{
			rotate(a);
			ft_printf("ra\n");
		}
		push(a, b);
		ft_printf("pb\n");
	}
	sort_3_elements(a);
	if (b->elements[0] < b->elements[1])
	{
		swap(b);
		ft_printf("sb\n");
	}
	push(b, a);
	push(b, a);
	ft_printf("pa\npa\n");
}

void	sort_4_elements(t_st *a, t_st *b)
{
	while (a->elements[a->front] != 0)
	{
		rotate(a);
		ft_printf("ra\n");
	}
	push(a, b);
	ft_printf("pb\n");
	sort_3_elements(a);
	push(b, a);
	ft_printf("pa\n");
}

void	sort_3_elements(t_st *a)
{
	size_t	mid_idx;

	mid_idx = next_idx(a->front, a->max_size);
	if ((a->elements[a->front] < a->elements[a->back]) && (a->elements[mid_idx] > a->elements[a->back]))
	{
		reverse_rotate(a);
		swap(a);
		ft_printf("rra\nsa\n");
	}
	else if ((a->elements[a->front] < a->elements[a->back]) && (a->elements[a->front] > a->elements[mid_idx]))
	{
		swap(a);
		ft_printf("sa\n");
	}
	else if ((a->elements[a->front] > a->elements[a->back]) && (a->elements[a->front] < a->elements[mid_idx]))
	{
		reverse_rotate(a);
		ft_printf("rra\n");
	}
	else if ((a->elements[a->front] > a->elements[mid_idx]))
	{
		rotate(a);
		ft_printf("ra\n");
		mid_idx = next_idx(a->front, a->max_size);
		if (a->elements[a->front] > a->elements[mid_idx])
		{
			swap(a);
			ft_printf("sa\n");
		}
	}
}

void	mini_sorting(t_ps *ps)
{
	if (ps->a.size == 2)
	{
		if (ps->a.elements[0] > ps->a.elements[1])
		{
			swap(&(ps->a));
			ft_printf("sa\n");
		}
	}
	else if (ps->a.size == 3)
		sort_3_elements(&(ps->a));
	else if (ps->a.size == 4)
		sort_4_elements(&(ps->a), &(ps->b));
	else if (ps->a.size == 5)
		sort_5_elements(&(ps->a), &(ps->b));
	return ;
}
