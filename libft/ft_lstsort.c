/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:41:41 by smiranda          #+#    #+#             */
/*   Updated: 2024/08/16 16:51:11 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsort(t_list *list)
{
	t_list	*ptr;
	t_list	*next;
	char	*temp;

	ptr = list;
	while (ptr)
	{
		next = ptr->next;
		while (next)
		{
			if (ft_strcmp(ptr->content, next->content) > 0)
			{
				temp = ptr->content;
				ptr->content = next->content;
				next->content = temp;
			}
			next = next->next;
		}
		ptr = ptr->next;
	}
	return (list);
}
