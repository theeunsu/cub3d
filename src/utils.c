/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:29:54 by eahn              #+#    #+#             */
/*   Updated: 2024/10/23 18:19:45 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	get_map_size(char *line, t_map *map)
{
	int		temp_width;
	char	*t_line;

	t_line = ft_strtrim(line, "\n");
	temp_width = ft_strlen(t_line);
	if (temp_width == 0 && map->height > 0)
	{
		free(t_line);
		print_error("Empty line found in the map.\n");
	}
	if (temp_width > 0 && (t_line[0] == '1' || t_line[0] == '0'
			|| t_line[0] == ' '))
	{
		if (temp_width > map->width)
			map->width = temp_width;
		map->height++;
	}
	free(t_line);
}

void	get_map(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open file.\n");
	line = get_next_line(fd);
	while (line)
	{
		get_map_size(line, map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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
