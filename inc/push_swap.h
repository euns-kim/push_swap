/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:44:48 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/12 23:00:03 by eunskim          ###   ########.fr       */
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

typedef struct s_reference_points
{
	size_t	max;
	size_t	mid;
	size_t	min;
	size_t	pivot[2];
}	t_rp;

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
	t_rp	marked;
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

void	ss(t_ps *ps);
void	rr(t_ps *ps);
void	rrr(t_ps *ps);

int		ps_strcmp(const char *s1, const char *s2);
int		command(t_ps *ps, char *command);

size_t	prev_idx(size_t curr_idx, size_t max_size);
size_t	next_idx(size_t curr_idx, size_t max_size);

int		read_command(t_ps *ps);
int		is_sorted(t_st a, t_st b);
int		init_program(t_ps *ps, int argc, char **argv);

int		get_pivots(t_ps *ps);
int		copy_stack_a(t_ps *ps, size_t *tmp_arr_to_sort);
void	calculate_pivots(t_ps *ps, t_rp *marked);
void	heap_sort(t_ps *ps, size_t *tmp_arr_to_sort);
void	heapify(size_t *arr, size_t n, size_t i);
void	swap_in_array(size_t *a, size_t *b);

size_t	*get_sorted_order(size_t arr_size, int *tmp_arr);
size_t	get_index(int *tmp_arr, size_t i, size_t arr_size);

void	mini_sorting(t_ps *ps);
void	sort_2_elements(t_st *a);
void	sort_3_elements(t_st *a);

// void	partitioning(t_ps *ps, t_rp *marked);

#endif