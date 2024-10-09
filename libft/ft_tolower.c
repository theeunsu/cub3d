/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:52:11 by eahn              #+#    #+#             */
/*   Updated: 2024/03/12 17:41:37 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main (void)
// {
//     printf("%d\n", ft_tolower('a'));
//     printf("%d\n", ft_tolower('A'));
//     printf("%d\n", ft_tolower('#'));

//     printf("%d\n", tolower('a'));
//     printf("%d\n", tolower('A'));
//     printf("%d\n", tolower('#'));
// }
