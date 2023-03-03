/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:37:47 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/03 16:37:57 by eunskim          ###   ########.fr       */
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

typedef struct s_stack
{
	int		*elements;
	size_t	front;
	size_t	back;
	size_t	size;
	size_t	max_size;
}	t_st;

typedef struct s_push_swap
{
	t_st	a;
	t_st	b;
}	t_ps;

int		main(int argc, char **argv);

int		split_and_error_check(t_ps *ps, char *input);
int		argv_error_check(t_ps *ps, int argc, char **argv);
int		parse_only_int(size_t arr_len, char	**input_arr, int *tmp_arr);
size_t	get_arr_len(char **arr);
int		int_checker(char *str, long long *sum);
int		check_string_end(char **str);
void	pass_white_spaces(char **str);
int		dup_check(int *arr, size_t arr_len);
int		initiate_stacks(t_st *a, t_st *b, int *tmp_arr, size_t arr_len);
void	print_stacks(t_st a, t_st b);
void	free_array(char	**ptr);
void	free_p(char *p);

int		pop_back(t_st *st);
int		pop_front(t_st *st);
void	push_back(t_st *st, int new);
void	push_front(t_st *st, int new);

void	push(t_st *from, t_st *to);
void	swap(t_st *stack);
void	rotate(t_st *stack);
void	reverse_rotate(t_st *stack);

void	ss(t_ps ps);
void	rr(t_ps ps);
void	rrr(t_ps ps);

#endif