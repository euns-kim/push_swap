/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:26:26 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/14 23:53:53 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_command_to_list()
{

}

void	add_command_to_list()
{

}

t_cn	*new_command_node(char *command)
{
	t_cn	*new;

	new = 0;
	new = (t_cn *) malloc(sizeof(t_cn));
	if (new == 0)
		return (0);
	new->cmd = command;
	new->prev = 0;
	new->next = 0;
	return (new);
}

1. each time save command in a node and add it to a list
2. optimize commands, save to another list, execute and print commands
3. free all

sa\n ----> sb\n == ss\n
sb\n ----> sa\n == ss\n
ra\n ----> rb\n == rr\n
rb\n ----> ra\n == rr\n
rra\n ----> rrb\n == rrr\n
rrb\n ----> rra\n == rrr\n

pa\n ----> pb\n == x
pb\n ----> pa\n == x
sa\n ----> sa\n == x
sb\n ----> sb\n == x
ra\n ----> rra\n == x
rra\n ----> ra\n == x
rb\n ----> rrb\n == x
rrb\n ----> rb\n == x

...