/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:05:41 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/23 22:37:07 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// modified atoi for push_swap to detect
// 1) if the input element is a number in the integer range
// 2) if there is any non-digit character inside the string
//		other than signs (+, -) at the first place
// in case of overflow/underflow, or non-integer character detection,
//		it will return 0 as an error code
//		-> print "Error\n" and stop the program immediately

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

void	pass_white_spaces(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

int	push_swap_atoi(char *str, long long *sum)
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
	if ((*str != '\0' && !(ft_isdigit(*str))) || dgt_cnt == 0)
		return (0);
	*sum = *sum * sign;
	return (1);
}
