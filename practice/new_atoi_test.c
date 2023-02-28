
./* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_atoi_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:59:17 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/24 23:37:05 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	main(void)
{
	long long	number;

	number = 0;
	printf("%d\t%lld\n", int_checker("		-12   9", &number), number);
	printf("%d\t%lld\n", int_checker("		12		 ", &number), number);
	printf("%d\t%lld\n", int_checker("f4", &number), number);
	printf("%d\t%lld\n", int_checker(" 34", &number), number);
	printf("%d\t%lld\n", int_checker(" 3f4", &number), number);
	printf("%d\t%lld\n", int_checker(" 	2356788833333", &number), number);
	printf("%d\t%lld\n", int_checker("345", &number), number);
	printf("%d\t%lld\n", int_checker("+345", &number), number);
	printf("%d\t%lld\n", int_checker("-345", &number), number);
	printf("%d\t%lld\n", int_checker("fg", &number), number);
	printf("%d\t%lld\n", int_checker("", &number), number);
	printf("%d\t%lld\n", int_checker(" ", &number), number);
}
