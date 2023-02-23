/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:46 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/23 19:29:25 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// input
// - should be a number in the integer range
// - cannot be duplicated

// otherwise
// "Error\n" in the standard error

int	main(int argc, char **argv)
{
	char	**input;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
	}

	input_error_check();
	init_stack();

	// calloc() t_ps
}
