/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:53:35 by eahn              #+#    #+#             */
/*   Updated: 2024/03/13 14:56:43 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*문자열 haystack 에서 needle을 n길이까지 찾아줌*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	unsigned int	i;
// 	unsigned int	j;

// 	if (ft_strlen(needle) == 0)
// 		return ((char *)haystack);
// 	if (haystack == 0 && len == 0)
// 		return (0);
// 	i = 0;
// 	while (haystack[i] != '\0' && i < len)
// 	{
// 		j = 0;
// 		while (haystack[i + j] == needle[j])
// 		{
// 			if (needle[j + 1] == '\0')
// 				return ((char *)haystack + i);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int main (void)
// {
//     char haystack[] = "Have a nice day";
//     char needle1[] = "nice";
//     // char needle2[] = "nike";
//     // char needle3[] = "";

//     printf("test 1: %s\n", ft_strnstr(haystack, needle1, 15));
//     printf("test 2: %s\n", ft_strnstr(haystack, needle1, 5));
//     printf("test 1: %s\n", strnstr(haystack, needle1, 15));
//     printf("test 2: %s\n", strnstr(haystack, needle1, 5));
// }
