/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:31:07 by eahn              #+#    #+#             */
/*   Updated: 2024/03/07 11:30:20 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// #include <stdio.h>

// int main(void) {
//     printf("Is '3' digit? %d\n", ft_isdigit('3'));
//     printf("Is 3 digit? %d\n", ft_isdigit(3));
//     printf("Is 'a' digit? %d\n", ft_isdigit('a'));
//     printf("Is '#' digit? %d\n", ft_isdigit('#'));

//     return (0);
// }