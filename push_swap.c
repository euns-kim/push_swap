/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:46 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/22 15:56:21 by eunskim          ###   ########.fr       */
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
	if (argc < 2)
		return (0);
	if (argc == 2)
		ft_split();
	input_error_check();
	init_stack();

	// calloc() t_ps
}
