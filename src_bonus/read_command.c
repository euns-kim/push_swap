/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:17:57 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/22 16:54:21 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* a function to read commands from stdin */

int	read_command(t_ps *ps)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (command(ps, line))
		{
			free(line);
			write(STDERR_FILENO, "Error\n", 7);
			return (EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (EXIT_SUCCESS);
}
