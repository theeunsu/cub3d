/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:16:00 by eahn              #+#    #+#             */
/*   Updated: 2024/03/12 17:39:28 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dst_ptr;

	dst_ptr = dst;
	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		while (len--)
			*(char *)(dst + len) = *(unsigned char *)(src + len);
	}
	else
	{
		while (len--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	return (dst_ptr);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char array[10];

// 	memset(array, 0, sizeof(array));
// 	strcpy(array, "test");

// 	printf("original : %s\n", array);

// 	memmove(array + 2, array, strlen("test"));

// 	printf("after memmove : %s\n", array);

// 	return (0);
// }
