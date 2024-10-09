/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:44:22 by eahn              #+#    #+#             */
/*   Updated: 2024/03/12 17:58:26 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
문자열 s1에 문자열 s2를 이어 붙여서 새로운 문자열로 반환한다.
원본 문자열을 수정하지 않고, 이어 붙여진 새로운 문자열이 필요할 때 사용
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcpy(new_str + (s1_len), s2, s2_len + 1);
	return (new_str);
}

// int	main(void)
// {
// 	char str1[] = "Hello";
// 	char str2[] = "World!";

// 	printf("%s\n", ft_strjoin(str1, str2));

// 	return (0);
// }
