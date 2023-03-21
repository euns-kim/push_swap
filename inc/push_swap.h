/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:44:48 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/21 21:17:57 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef enum e_command
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_cmd;

typedef struct s_cost_calculation
{
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
	size_t step_cnt;
}	t_cc;

typedef struct s_stack
{
	size_t	*elements;
	size_t	front;
	size_t	back;
	size_t	size;
	size_t	max_size;
}	t_st;

typedef struct s_push_swap
{
	t_st	a;
	t_st	b;
	size_t	pivot[2];
}	t_ps;

int		main(int argc, char **argv);

int		split_and_error_check(t_ps *ps, char *input);
int		argv_error_check(t_ps *ps, int argc, char **argv);
int		parse_only_int(size_t arr_len, char	**input_arr, int *tmp_arr);
size_t	get_arr_len(char **arr);
int		int_checker(char *str, long long *sum);
int		check_string_end(char **str);
void	pass_spaces(char **str);
int		dup_check(int *arr, size_t arr_len);
int		initiate_stacks(t_st *a, t_st *b, int *tmp_arr, size_t arr_len);
void	print_stacks(t_st a, t_st b);
void	free_array(char	**ptr);
void	free_p(char *p);
void	free_before_terminating(t_ps *ps);

int		pop_back(t_st *st);
int		pop_front(t_st *st);
void	push_back(t_st *st, int new);
void	push_front(t_st *st, int new);

void	push(t_st *from, t_st *to);
void	swap(t_st *stack);
void	rotate(t_st *stack);
void	reverse_rotate(t_st *stack);

void	swap_a_and_b(t_ps *ps);
void	rotate_a_and_b(t_ps *ps);
void	reverse_rotate_a_and_b(t_ps *ps);

int		ps_strcmp(const char *s1, const char *s2);
int		command(t_ps *ps, char *command);

size_t	prev_idx(size_t curr_idx, size_t max_size);
size_t	next_idx(size_t curr_idx, size_t max_size);

int		read_command(t_ps *ps);
int		is_sorted(t_st a, t_st b);
int		init_program(t_ps *ps, int argc, char **argv);

size_t	*get_sorted_order(size_t arr_size, int *tmp_arr);
size_t	get_index(int *tmp_arr, size_t i, size_t arr_size);

void	mini_sorting(t_ps *ps);
void	sort_3_elements(t_ps *ps, t_st *a);
void	sort_4_elements(t_ps *ps, t_st *a);
void	sort_5_elements(t_ps *ps, t_st *a, t_st *b);

void	calculate_pivots(t_ps *ps);
void	partitioning(t_ps *ps);

void	run_command(t_ps *ps, t_cmd val);
void	print_command(t_cmd val);
void	run_opt_commands(t_ps *ps, t_cc opt);

t_cc	find_the_optimal(t_st a, t_st b);
void	count_rb_rrb(t_st b, size_t b_idx, t_cc *curr);
size_t	get_index_from_0(t_st stack, size_t idx);
void	count_ra_rra(t_cc *curr, t_st a, size_t element_to_push);
size_t	search_from_front(t_st a, size_t element_to_push);
size_t	search_from_back(t_st a, size_t element_to_push);
void	count_steps(t_cc *curr);
int		stack_a_is_sorted(t_st a);
void	opt_rr_rrr(t_cc *curr);

int		sort_greedy(t_ps *ps);

#endif