/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:39:07 by eahn              #+#    #+#             */
/*   Updated: 2024/03/07 14:53:17 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*u_s1 != *u_s2)
			return (*u_s1 - *u_s2);
		u_s1++;
		u_s2++;
	}
	return (0);
}

// int	main(void)
// {
// 	int	a[2] = {42, 2};
// 	int	b[2] = {42, 2};

// 	printf("return: %d\n", ft_memcmp(a, b, sizeof(a)));
//     printf("return: %d\n", memcmp(a, b, sizeof(a)));
// 	return (0);
// }

// /* memory끼리 비교할 때는 char로 형변환해주는 것이 필요하다. */