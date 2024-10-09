/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:37:48 by eahn              #+#    #+#             */
/*   Updated: 2024/03/12 17:40:12 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
dst에 src를 size - 1만큼 복사하고 '\0'을 넣어주는
strcpy보다 안정성 있는 함수
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize < 1)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char dest[20];
// 	char src1[] = "Hello, World!";
// 	char src2[] = "This sentence is longer than destination size";
// 	char src3[] = "This senctence is to test buffer size";

// 	printf("Test 1: %zu\n", ft_strlcpy(dest, src1, 0));
// 	printf("Test 2: %zu\n", ft_strlcpy(dest, src2, 15));
// 	printf("Test 3: %zu\n", ft_strlcpy(dest, src3, 10));
// 	return (0);
// }
