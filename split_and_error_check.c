/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_error_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:58:20 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/25 01:21:46 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

unsigned int	len_check(char **arr)
{
	unsigned int	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}

int	split_and_error_check(t_ps *ps, char *input)
{
	char			**input_splitted;
	int				*tmp_arr;
	unsigned int	arr_len;
	long long		element;

	input_splitted = ft_split(input, ' ');
	if (input_splitted == NULL)
		return (0);
	arr_len = len_check(input_splitted);
	tmp_arr = ft_calloc(arr_len, sizeof(int));
	if (tmp_arr == NULL)
	{
		ft_printf("Calloc failed./n");
		exit(EXIT_FAILURE);
	}
	while (--arr_len >= 0)
	{
		if (!(int_checker(input_splitted[arr_len], &element)));
		{
			free(tmp_arr);
			free_array(input_splitted);
			exit(EXIT_FAILURE);
		}
		tmp_arr[arr_len] = (int) element;
	}
	// dup_check();
	// save tmp_arr to ps->a->elements
}
