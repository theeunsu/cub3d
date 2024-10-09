/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:02:58 by smiranda          #+#    #+#             */
/*   Updated: 2024/08/14 14:13:05 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *prev, char word)
{
	char	*new_buffer;
	int		length;
	int		i;

	if (!prev)
		length = 0;
	else
		length = ft_strlen(prev);
	new_buffer = ft_calloc((length + 2), 1);
	i = 0;
	if (prev)
	{
		while (prev[i])
		{
			new_buffer[i] = prev[i];
			i++;
		}
		free(prev);
	}
	new_buffer[i] = word;
	return (new_buffer);
}
