/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:40:26 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/26 15:40:56 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_p(char	*p)
{
	if (p)
		free(p);
}

void	free_array(char	**ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i] != 0);
		i++;
	}
	free(ptr);
}
