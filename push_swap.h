/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:13 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/15 22:15:49 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_stack_node
{
	int					num;	// number to be sorted
	unsigned int		idx;	// index of the number in input
	struct s_stack_node	*prev;	// previous node
	struct s_stack_node	*next;	// next node
}	t_sn;

typedef struct	s_stack
{
	t_sn			*front;		// node at the top of stack
	t_sn			*back;		// node at the bottom of stack
	t_sn			*them[2];	// front and back node saved in an array
	unsigned int	cnt;		// number of elements inside the current stack
}	t_s;

struct s_push_swap
{
	unsigned int	cnt;	// size of stack – number of elements in input
	t_s				a;		// stack a
	t_s				b;		// stack b
}	t_ps;

int		reverse_rotate(t_s *stack);
int		rotate(t_s *stack);
int		swap(t_s *stack);
int		push(t_s *from, t_s *to);

t_sn	*rm_back(t_s *stack);
t_sn	*rm_front(t_s *stack);
void	add_back(t_s *stack, t_sn *new);
void	add_front(t_s *stack, t_sn *new);
t_sn	*new_node(int num, unsigned int idx);