/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:42:27 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/14 22:51:54 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partitioning(t_ps *ps, t_rp *marked)
{
}

void	calculate_pivots(t_ps *ps, t_rp *marked)
{
	marked->max = ps->a.max_size - 1;
	marked->mid = ps->a.max_size / 2;
	marked->min = 0;
	marked->pivot[0] = marked->max / 3;
	marked->pivot[1] = marked->max * 2 / 3;
}
