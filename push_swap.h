/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:44:48 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/23 18:58:14 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

typedef struct	s_stack
{
	int				*elements;
	unsigned int	front;
	unsigned int	back;
	unsigned int	size;
	unsigned int	max_size;
}	t_st;

typedef struct	s_push_swap
{
	t_st	a;
	t_st	b;
}	t_ps;
