/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:15:47 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/07 18:48:28 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_ps *ps)
{
	reverse_rotate(&ps->a);
	reverse_rotate(&ps->b);
}

void	rr(t_ps *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
}

void	ss(t_ps *ps)
{
	swap(&ps->a);
	swap(&ps->b);
}
