/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:27:25 by eahn              #+#    #+#             */
/*   Updated: 2024/10/21 17:00:33 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



static void	parse_grid(t_map *map, char *line)
{
	int	line_length;

	if (map->grid == NULL)
	{
		map->grid = (char **)ft_calloc(map->height, sizeof(char *));
		if (!map->grid)
			print_error("Failed to allocate memory for grid.\n");
	}
	map->grid[map->lcount] = ft_calloc(map->width + 1, sizeof(char));
	if (!map->grid[map->lcount])
		print_error("Failed to allocate memory for grid line.\n");
	ft_strncpy(map->grid[map->lcount], line, map->width);
	line_length = strlen(line);
	if (line_length < map->width)
		ft_memset(map->grid[map->lcount] + line_length, ' ', map->width
			- line_length);
	map->lcount++;
}

static void	process_line(char *line, t_game *game)
{
	line = ft_strtrim(line, "\n");
	if (line[0] == '\0')
		return ;
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		parse_direction(&game->map, line);
	else if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		parse_color(&game->map, line, line[0]);
	else if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
		parse_grid(&game->map, line);
	free(line);
	return ;
}

void	get_map_size(char *line, t_map *map)
{
	int	temp_width;

	line = ft_strtrim(line, "\n");
	temp_width = ft_strlen(line);
	if (temp_width == 0 && map->height > 0)
	{
		free(line);
		print_error("Empty line found in the map.\n");
	}
	if (temp_width > 0 && (line[0] == '1' || line[0] == '0' || line[0] == ' '))
	{
		if (temp_width > map->width)
			map->width = temp_width;
		map->height++;
	}
	free(line);
}

void	get_map(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open file.\n");
	while ((line = get_next_line(fd)))
		get_map_size(line, map);
	close(fd);
}


void	parse_map(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open file.\n");
	while ((line = get_next_line(fd)))
		process_line(line, game);
	validate_data(&game->map);
	validate_map(&game->map);
	close(fd);
}
