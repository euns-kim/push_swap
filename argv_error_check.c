/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:15:22 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/25 23:57:09 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_error_check(t_ps *ps, int argc, char **argv)
{
	int			*tmp_arr;

	tmp_arr = NULL;
	if (!(parse_only_int(argc - 1, ++argv, &tmp_arr))
		|| !(dup_check(tmp_arr, argc - 1)))
	{
		free(tmp_arr);
		return (EXIT_FAILURE);
	}
	ps->a.elements = tmp_arr;
	return (EXIT_SUCCESS);	
}
