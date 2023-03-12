/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:20:31 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/12 23:05:59 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_elements(t_st *a)
{
	if (a->elements[a->front] == 0 && a->elements[a->back] == 1)
	{
		reverse_rotate(a);
		swap(a);
		ft_printf("rra\nsa\n");
	}
	else if (a->elements[a->front] == 1 && a->elements[a->back] == 2)
	{
		swap(a);
		ft_printf("sa\n");
	}
	else if (a->elements[a->front] == 1 && a->elements[a->back] == 0)
	{
		reverse_rotate(a);
		ft_printf("rra\n");
	}
	else if (a->elements[a->front] == 2)
	{
		rotate(a);
		ft_printf("ra\n");
		if (a->elements[a->front] == 1)
		{
			swap(a);
			ft_printf("sa\n");
		}
	}
}

void	sort_2_elements(t_st *a)
{
	if (a->elements[0] > a->elements[1])
	{
		swap(a);
		ft_printf("sa\n");
	}
	return ;
}

void	mini_sorting(t_ps *ps)
{
	if (ps->a.max_size == 2)
		sort_2_elements(&(ps->a));
	else if (ps->a.max_size == 3)
		sort_3_elements(&(ps->a));
	// else if (ps->a.max_size == 3)
	// else if (ps->a.max_size == 5)
}
