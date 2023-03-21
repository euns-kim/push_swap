/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:44:36 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/19 16:44:43 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_command
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_cmd;

typedef struct	s_command_node
{
	t_cmd					cmd;	// enum for each cmd
	struct s_command_node	*next;	// next node
}	t_cn;

typedef struct	s_command_list
{
	struct s_command_node	*start; // first node of command list
	struct s_command_node	*start_opitmized; // first node of optimized command list
}	t_cl;