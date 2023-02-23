/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_atoi_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:59:17 by eunskim           #+#    #+#             */
/*   Updated: 2023/02/23 22:32:24 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	long long	number;

	number = 0;
	printf("%d\n%lld\n", push_swap_atoi("		-12", &number), number);
	printf("%d\n%lld\n", push_swap_atoi("		12f", &number), number);
	printf("%d\n%lld\n", push_swap_atoi("f4", &number), number);
	printf("%d\n%lld\n", push_swap_atoi(" 34", &number), number);
	printf("%d\n%lld\n", push_swap_atoi(" 3f4", &number), number);
	printf("%d\n%lld\n", push_swap_atoi(" 	-23567888", &number), number);
	printf("%d\n%lld\n", push_swap_atoi("345", &number), number);
	printf("%d\n%lld\n", push_swap_atoi("+345", &number), number);
	printf("%d\n%lld\n", push_swap_atoi("-345", &number), number);
	printf("%d\n%lld\n", push_swap_atoi("fg", &number), number);
	printf("%d\n%lld\n", push_swap_atoi("", &number), number);
	printf("%d\n%lld\n", push_swap_atoi(" ", &number), number);
}
