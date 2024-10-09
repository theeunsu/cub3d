/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:04:01 by eahn              #+#    #+#             */
/*   Updated: 2024/03/14 12:01:55 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

/*
while 루프 내에서 문자열을 검색하는 동안 문자가 발견되지 않고 루프를 빠져나오게 되면,
*str이 NULL에 도달하게 됩니다. 이 경우, if 문이 루프 바깥에 존재하여 마지막으로
검사된 문자가 찾고자 하는 문자인지 확인하고, 만약 찾고자 하는 문자가 마지막 문자인 경우, 해당 문자의 포인터를 반환합니다.
*/

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *src = "123456123";

// 	printf("return: %s\n", ft_strchr(src, '3'));
// 	printf("return: %s\n", ft_strchr(src, '9'));
// 	printf("return: %s\n", strchr(src, '3'));
// 	printf("return: %s\n", strchr(src, '9'));
// }