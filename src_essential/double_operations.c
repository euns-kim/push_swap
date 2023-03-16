/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:15:47 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/14 23:12:25 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a_and_b(t_ps *ps)
{
	reverse_rotate(&ps->a);
	reverse_rotate(&ps->b);
}

void	rotate_a_and_b(t_ps *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
}

void	swap_a_and_b(t_ps *ps)
{
	swap(&ps->a);
	swap(&ps->b);
}
