/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:46:28 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/26 18:02:26 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_st a, t_st b)
{
	size_t i;
	
	i = 0;
	printf("stack a: ");
	while (i < a.max_size)
	{
		printf("%d\t", a.elements[i]);
		i++;
	}
	printf("\n");
	printf("a_front: %d\n", a.front);
	printf("a_back: %d\n", a.back);
	printf("a_size: %d\n", a.size);
	printf("a_max_size: %d\n", a.max_size);
	i = 0;
	printf("stack b: ");
	while (i < b.max_size)
	{
		printf("%d\t", b.elements[i]);
		i++;
	}
	printf("\n");
	printf("b_front: %d\n", b.front);
	printf("b_back: %d\n", b.back);
	printf("b_size: %d\n", b.size);
	printf("b_max_size: %d\n", b.max_size);
}