/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:54:01 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/16 21:27:02 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstclear(t_cn **lst)
{
	t_cn	*curr;
	t_cn	*next;

	curr = *lst;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*lst = 0;
}

void	ps_lstadd_back(t_cn **lst, t_cn *new)
{
	t_cn	*last;

	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	last = ps_lstlast(*lst);
	last->next = new;
}

t_cn	*ps_lstlast(t_cn *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

t_cn	*ps_lstnew(t_cmd cmd)
{
	t_cn	*new;

	new = 0;
	new = (t_cn *) malloc(sizeof(t_cn));
	if (new == 0)
		return (0);
	new->cmd = cmd;
	new->next = 0;
	return (new);
}
