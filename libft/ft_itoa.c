/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:35:34 by eahn              #+#    #+#             */
/*   Updated: 2024/03/11 23:58:50 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
integer to ascii: 인자로 들어온 int형 숫자를 char*로 전환하는 함수
*/

#include "libft.h"

static size_t	get_nb_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*n<0일 때는 음수부호를 고려하여 len++ 해줌*/

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	long	nb;

	len = get_nb_len(n);
	nb = n;
	result = malloc(len + 1);
	if (!(result))
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		result[0] = '0';
	result[len--] = '\0';
	while (nb)
	{
		result[len] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (result);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(1));
// 	return (0);
// }
