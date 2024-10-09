/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:57:49 by eahn              #+#    #+#             */
/*   Updated: 2024/03/07 11:30:13 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The	isalpha(void) function tests for any character
// for which isupper(3) or islower(3) is true.
// The value of the argument must be representable
// as an unsigned char or the value of EOF.

#include "libft.h" 

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// #include <stdio.h>

// int main(void) {
//     printf("Is 'A' alphabetic? %d\n", ft_isalpha('A'));
//     printf("Is '3' alphabetic? %d\n", ft_isalpha(3));
//     printf("Is 'a' alphabetic? %d\n", ft_isalpha('a'));
//     printf("Is '#' alphabetic? %d\n", ft_isalpha('#'));

//     return (0);
// }
