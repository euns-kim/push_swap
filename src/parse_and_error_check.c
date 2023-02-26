/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_error_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:46:48 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/26 17:54:52 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initiate_stacks(t_ps *ps, int *tmp_arr, size_t arr_len)
{
	int	*stack_b;
	
	stack_b = NULL;
	stack_b = ft_calloc(arr_len, sizeof(int));
	if (stack_b == NULL)
		return (EXIT_FAILURE);
	ps->a.elements = tmp_arr;
	ps->a.front = 0;
	ps->a.back = arr_len - 1;
	ps->a.size = arr_len;
	ps->a.max_size = arr_len;
	ps->b.elements = stack_b;
	ps->a.front = 0;
	ps->a.back = 0;
	ps->a.size = 0;
	ps->a.max_size = arr_len;
	return (EXIT_SUCCESS);
}

int	parse_only_int(size_t arr_len, char	**input_arr, int **tmp_arr)
{
	size_t		idx;
	long long	element;

	idx = 0;
	tmp_arr = ft_calloc(arr_len, sizeof(int));
	if (tmp_arr == NULL)
		return (EXIT_FAILURE);
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

	tmp_arr = NULL;
	if (parse_only_int(argc - 1, ++argv, &tmp_arr)
		|| dup_check(tmp_arr, argc - 1)
		|| initiate_stacks(ps, tmp_arr, argc - 1))
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
	tmp_arr = NULL;
	arr_len = get_arr_len(input_splitted);
	if (arr_len < 2)
		return (EXIT_FAILURE);
	if (parse_only_int(arr_len, input_splitted, &tmp_arr)
		|| dup_check(tmp_arr, arr_len)
		|| initiate_stacks(ps, tmp_arr, arr_len))
	{
		free_p(tmp_arr);
		free_array(input_splitted);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
