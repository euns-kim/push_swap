/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:46 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/26 00:03:48 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		if (!(split_and_error_check(&ps, argv[1])))
		{
			ft_printf("Parsing failed.");
			// Error\n" in the standard error
			EXIT(EXIT_FAILURE);
		}
	}
	else
	{
		if (!(argv_error_check(&ps, argc, argv)))
		{
			ft_printf("Parsing failed.");
			// Error\n" in the standard error
			EXIT(EXIT_FAILURE);
		}
	}

	// init_stack();
}
