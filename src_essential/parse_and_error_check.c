/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_error_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:46:48 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/07 22:22:47 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initiate_stacks(t_st *a, t_st *b, int *tmp_arr, size_t arr_len)
{
	int	*stack_b;

	stack_b = ft_calloc(arr_len, sizeof(int));
	if (stack_b == NULL)
		return (EXIT_FAILURE);
	a->elements = tmp_arr;
	a->front = 0;
	a->back = arr_len - 1;
	a->size = arr_len;
	a->max_size = arr_len;
	b->elements = stack_b;
	b->front = 0;
	b->back = 0;
	b->size = 0;
	b->max_size = arr_len;
	return (EXIT_SUCCESS);
}

int	parse_only_int(size_t arr_len, char	**input_arr, int *tmp_arr)
{
	size_t		idx;
	long long	element;

	idx = 0;
	while (idx < arr_len)
	{
		if ((int_checker(input_arr[idx], &element)))
			return (EXIT_FAILURE);
		tmp_arr[idx] = (int) element;
		idx++;
	}
	return (EXIT_SUCCESS);
}

int	argv_error_check(t_ps *ps, int argc, char **argv)
{
	int			*tmp_arr;

	tmp_arr = ft_calloc(argc - 1, sizeof(int));
	if (tmp_arr == NULL)
		return (EXIT_FAILURE);
	if (parse_only_int(argc - 1, ++argv, tmp_arr)
		|| dup_check(tmp_arr, argc - 1)
		|| initiate_stacks(&(ps->a), &(ps->b), tmp_arr, argc - 1))
	{
		free(tmp_arr);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	split_and_error_check(t_ps *ps, char *input)
{
	char		**input_splitted;
	int			*tmp_arr;
	size_t		arr_len;

	input_splitted = ft_split(input, ' ');
	if (input_splitted == NULL)
		return (EXIT_FAILURE);
	arr_len = get_arr_len(input_splitted);
	if (arr_len < 2)
		return (EXIT_FAILURE);
	tmp_arr = ft_calloc(arr_len, sizeof(int));
	if (tmp_arr == NULL)
		return (EXIT_FAILURE);
	if (parse_only_int(arr_len, input_splitted, tmp_arr)
		|| dup_check(tmp_arr, arr_len)
		|| initiate_stacks(&(ps->a), &(ps->b), tmp_arr, arr_len))
	{
		free_p((char *) tmp_arr);
		free_array(input_splitted);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_program(t_ps *ps, int argc, char **argv)
{
	if (argc == 2)
	{
		if (split_and_error_check(ps, argv[1]))
		{
			write(STDERR_FILENO, "Error\n", 7);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		if (argv_error_check(ps, argc, argv))
		{
			write(STDERR_FILENO, "Error\n", 7);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
