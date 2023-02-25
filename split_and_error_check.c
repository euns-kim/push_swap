/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_error_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:58:20 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/26 00:04:53 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_check(int *arr, size_t arr_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_len)
	{
		j = 0;
		while (i + j < arr_len)
		{
			if (arr[i] == arr[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_p(char	*p)
{
	if (p)
		free(p);
}

void	free_array(char	**ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i] != 0);
		i++;
	}
	free(ptr);
}

size_t	get_arr_len(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
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
	if (!(parse_only_int(arr_len, input_splitted, &tmp_arr))
		|| !(dup_check(tmp_arr, arr_len)))
	{
		free_p(tmp_arr);
		free_array(input_splitted);
		return (EXIT_FAILURE);
	}
	ps->a.elements = tmp_arr;
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
		if (!(int_checker(input_arr[idx], &element)))
			return (EXIT_FAILURE);
		tmp_arr[idx] = (int) element;
		idx++;
	}
	return (EXIT_SUCCESS);
}