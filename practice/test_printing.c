/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:46:28 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/07 22:23:33 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_st a, t_st b)
{
	size_t	i;
	size_t	idx;

	i = 0;
	idx = a.front;
	ft_printf("\n");
	ft_printf("stack a: ");
	while (i < a.size)
	{
		ft_printf("%d\t", a.elements[idx]);
		idx = next_idx(idx, a.max_size);
		i++;
	}
	ft_printf("\n");
	ft_printf("a_front: %d\n", a.front);
	ft_printf("a_back: %d\n", a.back);
	ft_printf("a_size: %d\n", a.size);
	ft_printf("a_max_size: %d\n", a.max_size);
	ft_printf("\n");
	i = 0;
	idx = b.front;
	ft_printf("stack b: ");
	while (i < b.size)
	{
		ft_printf("%d\t", b.elements[idx]);
		idx = next_idx(idx, b.max_size);
		i++;
	}
	ft_printf("\n");
	ft_printf("b_front: %d\n", b.front);
	ft_printf("b_back: %d\n", b.back);
	ft_printf("b_size: %d\n", b.size);
	ft_printf("b_max_size: %d\n", b.max_size);
}
