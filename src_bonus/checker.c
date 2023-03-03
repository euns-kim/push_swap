/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:16:16 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/03 22:20:55 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	char	*line;

	if (argc < 2)
		return (EXIT_FAILURE);
	else if (argc == 2)
	{
		if (split_and_error_check(&ps, argv[1]))
		{
			write(STDERR_FILENO, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (argv_error_check(&ps, argc, argv))
		{
			write(STDERR_FILENO, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
	}
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (command(ps, line))
		{
			free(line);
			write(STDERR_FILENO, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		ft_printf("%s", line);
		free(line);
	}
}
