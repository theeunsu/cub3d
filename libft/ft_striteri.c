/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:06:26 by eahn              #+#    #+#             */
/*   Updated: 2024/03/12 14:28:40 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 문자열 s를 순회하며 각 요소에 함수 f를 적용시키는 함수
strmapi 함수와는 달리 새 문자열을 생성하지 않고, 대신 함수 포인터의 두번째 매개변수로
각 문자의 주소값을 사용하여 기존 문자열에 저장되어 있는 값들을 변화시킨다
*/
void	ft_striteri(char *s, void (*f)(unsigned int i, char *))
{
	unsigned int	i;

	i = 0;
	while (*s)
		f(i++, s++);
}

// void	function(unsigned int i, char *c)
// {
// 	*c += i;
// }
// int	main(void)
// {
// 	char	str[] = "aaaaaa";

// 	ft_striteri(str, &function);
// 	printf("%s\n", str);
// 	return (0);
// }
/*일반적으로 메모리와 관련된 작업을 할 때는 'size_t'를 사용하고,
일반적인 정수 연산에는 'unsigned int'를 사용한다 */
