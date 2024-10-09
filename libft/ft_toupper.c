/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:31 by eahn              #+#    #+#             */
/*   Updated: 2024/03/07 11:29:09 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main (void)
// {
//     printf("%d\n", ft_toupper('a'));
//     printf("%d\n", ft_toupper('A'));
//     printf("%d\n", ft_toupper('#'));
//     printf("%d\n", toupper('a'));
//     printf("%d\n", toupper('A'));
//     printf("%d\n", toupper('#'));

//     return (0);
// }