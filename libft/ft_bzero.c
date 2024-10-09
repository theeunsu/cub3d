/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:09:03 by eahn              #+#    #+#             */
/*   Updated: 2024/03/12 17:37:32 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}

/*
* 인자로 들어온 주소값 s를 (unsigned char *)으로 형변환 해줘야 한다.
--> unsigned char가 아닌 signed char의 경우,
	1의 보수 표현이나 부호-크기 방식(signed magnitude)방식으로 표현했을 시 -0을 가질 수 있다.
	-0은 null character가 될 수 없으므로 unsigned char로 접근하기를 요구하고 있다.
* size_t :
  시스템에서 어떤 객체나 값이 포함할 수 있는 최대 크기의 데이터를 표현하는 타입으로 반드시 unsigned형으로 나타낸다.
  컴퓨터의 운영체제(x32 or x64)에 따라 size_t는 unsigned int, unsigned long long으로 나뉜다.
*/

// #include <stdio.h>

// int	main(void)
// {
// 	// 테스트할 메모리 영역
// 	char str[] = "Hello, World!";
// 	size_t n = sizeof(str); // 널 종료 포함 제외 길이

// 	// ft_bzero 함수 호출
// 	printf("Original string: %s\n", str);
// 	ft_bzero(str, n);
// 	printf("After ft_bzero: %s\n", str);

// 	return (0);
// }
