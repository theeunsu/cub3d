/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:09:13 by eahn              #+#    #+#             */
/*   Updated: 2024/07/19 11:36:47 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = start;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	result = (char *)ft_calloc(len + 1, 1);
	if (!result)
		return (NULL);
	while (i < len && s[j] != '\0')
	{
		result[i++] = s[j++];
	}
	result[i] = '\0';
	return (result);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*sub;

// 	if (!s || ft_strlen(s) < start)
// 		return (NULL);
// 	sub = (char *)malloc(len + 1);
// 	if (!sub)
// 		return (NULL);
// 	i = start;
// 	j = 0;
// 	while (i < ft_strlen(s) && j < len)
// 		sub[j++] = s[i++];
// 	sub[j] = '\0';
// 	return (sub);
// }

// int	main(void)
// {
// 	char	*str;

// 	str = ft_substr("Hello, World!", 7, 5);
// 	printf("%s\n", str);
// 	return (0);
// }
// /*
// 원본 문자열 s에서 하위 문자열을 하나 만들어줘서 리턴해줌.
// 하위 문자열은 start에서부터 len만큼의 길이를 갖고 있다.
// s: The string from which to create the substring.
// start: The start index of the substring in the string ’s’.
// len: The maximum length of the substring.

// Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.

// */
