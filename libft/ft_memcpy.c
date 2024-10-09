/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:25:16 by eahn              #+#    #+#             */
/*   Updated: 2024/03/07 11:28:28 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst_ptr;

	dst_ptr = dst;
	if (dst == 0 && src == 0)
		return (0);
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (dst_ptr);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char src[32] = "Hello World!";
// 	char dest[32] = "This is destination";
//  char dest_2[32] = "This is destination_2";

// 	printf("Destination: \"%s\"\n", dest);
// 	ft_memcpy(dest, src, sizeof(src));
// 	printf("After memcpy, Destination becomes \"%s\"\n", dest);

//     printf("Destination: \"%s\"\n", dest_2);
// 	memcpy(dest_2, src, sizeof(src));
// 	printf("After memcpy, Destination becomes \"%s\"\n", dest_2);
// }