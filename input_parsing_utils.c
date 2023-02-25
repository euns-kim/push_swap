/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:05:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/24 23:42:16 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// modified atoi-like function for push_swap to detect
// 1) if the input element is a number in the integer range
// 2) if there is any non-digit character inside the string
//	other than signs (+, -) at the first place and white-spaces
// 3) when there is another digit following after the int parsing,
//	it will be regarded as an invalid input.
// 4) in case of overflow/underflow, or extra character detection,
//	it will return 0 as an error code
//	-> print "Error\n" and stop the program immediately

void	pass_white_spaces(char **str)
{
	while (**str == ' ' || **str == '\f' || **str == '\n'
		|| **str == '\r' || **str == '\t' || **str == '\v')
		(*str)++;
}

int	check_string_end(char **str)
{
	pass_white_spaces(str);
	if (**str != '\0')
		return (0);
	else
		return (1);
}

int	int_checker(char *str, long long *sum)
{
	int	dgt_cnt;
	int	sign;

	*sum = 0;
	dgt_cnt = 0;
	sign = 1;
	pass_white_spaces(&str);
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
			return (0);
		str++;
	}
	*sum = *sum * sign;
	if (!(check_string_end(&str)) || dgt_cnt == 0)
		return (0);
	return (1);
}
