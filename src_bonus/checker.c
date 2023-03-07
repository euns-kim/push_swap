/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:16:16 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/07 22:18:14 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (init_program(&ps, argc, argv))
		return (EXIT_FAILURE);
	read_command(&ps);
	if (is_sorted(ps.a, ps.b))
		write(STDOUT_FILENO, "KO\n", 4);
	else
		write(STDOUT_FILENO, "OK\n", 4);
	free_before_terminating(&ps);
	return (EXIT_SUCCESS);
}
