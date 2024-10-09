/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:34:33 by eahn              #+#    #+#             */
/*   Updated: 2024/03/14 14:39:11 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
두 문자열을 붙이는 함수로, dst의 맨 뒤에 src를 dstsize만큼 붙인다.
만약 dstsize가 dst의 길이 이하라면 문자열을 붙이는 과정이 사라지고,
dstsize가 더 크다면 size - 1만큼 src를 붙이고 마지막에 '\0'값을 넣어주고
리턴 값은 dst 길이 + src의 길이이다.
*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize < dst_len + 1)
		return (dstsize + src_len);
	if (dstsize > dst_len + 1)
	{
		while (src[i] != '\0' && dst_len + 1 + i < dstsize)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// int main (void)
// {
//     char dest[30] = "123";
//     char *src = "456789";

//     size_t ret ;
//     ret = ft_strlcat(dest, src, 20);
//     printf("dest = %s\nreturn (= %zu", dest, ret));
// }