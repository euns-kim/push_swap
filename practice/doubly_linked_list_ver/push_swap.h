/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:13 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/22 17:47:52 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_stack_node
{
	int					num;	// number to be sorted
	unsigned int		idx;	// index of the number in input (is this really needed?)
	struct s_stack_node	*prev;	// previous node
	struct s_stack_node	*next;	// next node
}	t_sn;

typedef struct	s_stack
{
	t_sn			*node[2];	// front and back node saved in an array
	unsigned int	cnt;		// number of elements inside the current stack
}	t_s;

typedef struct s_push_swap
{
	t_s				a;		// stack a
	t_s				b;		// stack b
	unsigned int	cnt;	// size of stack – number of elements in input	
}	t_ps;

typedef enum	e_end
{
	FRONT = 0,
	BACK = 1
}	t_end;

int		reverse_rotate(t_s *stack);
int		rotate(t_s *stack);
int		swap(t_s *stack);
int		push(t_s *from, t_s *to);


