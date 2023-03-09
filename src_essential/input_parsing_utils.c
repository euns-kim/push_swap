/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:05:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/08 17:13:36 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* a function to check if there is any duplicated number
inside the tmp_array where the parsed integers are saved */
int	dup_check(int *arr, size_t arr_len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < arr_len)
	{
		j = 1;
		while (i + j < arr_len)
		{
			if (arr[i] == arr[i + j])
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/* a function to pass spaces in the string
before and after a digit-unit to be detected */
void	pass_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

/* a function to check if the given string ends
without having characters other than spaces */
int	check_string_end(char **str)
{
	pass_spaces(str);
	if (**str == '\0')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

// Modified atoi-like function for push_swap to detect
// 1) if the input element is a number in the integer range, and
// 2) if there is any non-digit character inside the string
// 	other than signs (+, -) at the first place and spaces.
// When an integer is parsed and there is another digit following after,
// 	it will be regarded as an invalid input.
// In case of overflow/underflow, or extra character detection,
// 	it will return (EXIT_FAILURE) as an error code.
// 	-> print "Error\n" and stop the program immediately

int	int_checker(char *str, long long *sum)
{
	int	dgt_cnt;
	int	sign;

	*sum = 0;
	dgt_cnt = 0;
	sign = 1;
	pass_spaces(&str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		dgt_cnt++;
		*sum = *sum * 10 + (*str - '0');
		if ((*sum * sign > INT_MAX) || (*sum * sign < INT_MIN))
			return (EXIT_FAILURE);
		str++;
	}
	*sum = *sum * sign;
	if (check_string_end(&str) || dgt_cnt == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* a function to get the length of array */
size_t	get_arr_len(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}
