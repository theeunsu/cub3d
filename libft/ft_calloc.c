/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:05:09 by eahn              #+#    #+#             */
/*   Updated: 2024/03/12 17:48:22 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(size * count);
	if (!tmp)
		return (0);
	ft_bzero(tmp, (count * size));
	return (tmp);
}

/*
size를 count개수만큼 할당
*/

// int	main(void)
// {
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	str = (char *)ft_calloc(10, sizeof(char));
// 	while (i < 10)
// 	{
// 		str[i] += '0';
// 		i++;
// 	}
// 	printf("%s\n", str);
// 	free (str);
// }
