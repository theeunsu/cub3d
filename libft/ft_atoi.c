/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:30:19 by eahn              #+#    #+#             */
/*   Updated: 2024/07/18 17:39:56 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	minus;
	int	result;

	minus = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * minus);
}

// int	main(void)
// {
// 	char str1[] = " ---+--+1234ab567";
// 	char str2[] = " \n\r-12abb345";
// 	char str3[] = "123 123";
// 	char str4[] = "---123";
// 	printf("test 1: %d\n", ft_atoi(str1));
// 	printf("test 2: %d\n", ft_atoi(str2));
// 	printf("test 3: %d\n", ft_atoi(str3));
// 	printf("test 4: %d\n", ft_atoi(str4));
// 	printf("test 1: %d\n", atoi(str1));
// 	printf("test 2: %d\n", atoi(str2));
// 	printf("test 3: %d\n", atoi(str3));
// 	printf("test 4: %d\n", atoi(str4));

// 	return (0);
// }
