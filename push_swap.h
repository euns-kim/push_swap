/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:44:48 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/25 22:09:21 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	s_stack
{
	int		*elements;
	size_t	front;
	size_t	back;
	size_t	size;
	size_t	max_size;
}	t_st;

typedef struct	s_push_swap
{
	t_st	a;
	t_st	b;
}	t_ps;
