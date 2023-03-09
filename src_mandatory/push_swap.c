/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:46 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/08 17:11:47 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// First part of main is for the parsing of a list of integers,
// assuming that there are two types of valid input.
// One is "[a list of integers delimited by space]" in argv[1],
// the other is a list of integers as paraemters given.
// Cases are divided into three according to the value of argc.

// 1) If (argc < 2), the program simply gives the prompt back.
// 2) If (argc == 2), argv[1] should be splitted into an array of strings.
// 3) If (argc > 2), argv from index 1 will be the input to be handled.

// For 2) and 3) parsing and error checking will be done at the same time.
// In either case, one string should contain only one unit of digits.
// But spaces before and after the number unit will be tolerated.

// If every element is a valid integer, stacks will be already initiated.
// If not, allocated memory space will be freed
// and the program stops, printing "Error\n" in the standard error.

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (init_program(&ps, argc, argv))
		return (EXIT_FAILURE);
	if (get_pivots(&ps))
	{
		free_before_terminating(&ps);
		return (EXIT_FAILURE);
	}
	free_before_terminating(&ps);
//	print_stacks(ps.a, ps.b);
	return (EXIT_SUCCESS);
}
