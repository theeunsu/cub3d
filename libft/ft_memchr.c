/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:36:16 by eahn              #+#    #+#             */
/*   Updated: 2024/03/13 14:29:30 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* str의 포인터에서부터 n byte 만큼의 크기 안에서 c를 찾아서 해당 포인터를 리턴해주는 함수*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if ((*((unsigned char *)s)) == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *a = "123";

// 	printf("%s\n", ft_memchr(a, '2', 4));
// 	printf("%s\n", memchr(a, '2', 4));
// }
