/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:26:26 by eunskim           #+#    #+#             */
/*   Updated: 2023/03/16 21:26:38 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. each time save command in a node and add it to a list
// 2. optimize commands, save to another list, print commands
// 3. free all

// sa\n ----> sb\n == ss\n
// sb\n ----> sa\n == ss\n
// ra\n ----> rb\n == rr\n
// rb\n ----> ra\n == rr\n
// rra\n ----> rrb\n == rrr\n
// rrb\n ----> rra\n == rrr\n

// pa\n ----> pb\n == x
// pb\n ----> pa\n == x
// sa\n ----> sa\n == x
// sb\n ----> sb\n == x
// ra\n ----> rra\n == x
// rra\n ----> ra\n == x
// rb\n ----> rrb\n == x
// rrb\n ----> rb\n == x

// ...