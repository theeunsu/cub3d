/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:47:08 by eahn              #+#    #+#             */
/*   Updated: 2024/03/12 12:00:50 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*문자열 s를 함수 f에 적용시킨 새로운 문자열을 만들어서 리턴해주는 함수*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*result;

	i = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	result = (char *)malloc((sizeof(char) * (len + 1)));
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char	to_upper(unsigned int index, char c)
// {
// 	(void)index; // 인덱스 사용 안함
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32); // 소문자를 대문자로 변환하여 반환
// 	return (c);          // 대문자나 다른 문자인 경우 그대로 반환
// }

// int	main(void)
// {
// 	char	*str;

// 	str = ft_strmapi("HeLlO wOrLd!", to_upper);
// 	printf("%s\n", str);
// }
