/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:51:29 by eahn              #+#    #+#             */
/*   Updated: 2024/03/13 14:20:41 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((s[i]) == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *src = "123456123";

//  printf("return (: %s\n", ft_strrchr(src, '3')));
// 	printf("return (: %s\n", ft_strrchr(src, 0)));
// 	printf("return (: %s\n", ft_strrchr(src, '9')));
//  printf("return (: %s\n", strrchr(src, '3')));
// 	printf("return (: %s\n", strrchr(src, 0)));
// 	printf("return (: %s\n", strrchr(src, '9')));
// }
