/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:29:54 by eahn              #+#    #+#             */
/*   Updated: 2024/10/16 18:06:43 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>

void	get_map_size(char *line, t_map *map)
{
	int	i;
	int	temp_width;

	i = 0;
	if (line[i] == '\0')
		return ;
	temp_width = ft_strlen(line);
	while (line[i] != '\0')
	{
		if (line[0] == '1' || line[0] == '0')
		{
			if (temp_width > map->width)
				map->width = temp_width;
			map->height++;
			break;
		}
		i++;
	}
	printf("width: %d, height: %d\n", map->width, map->height);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		print_error("Malloc failed.\n");
	return (ptr);
}

void	print_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}
