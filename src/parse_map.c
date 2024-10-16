/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:27:25 by eahn              #+#    #+#             */
/*   Updated: 2024/10/16 16:05:50 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_color(t_map *map, char *line, char type)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	line = ft_strtrim(line + 2, " \n");
	colors = ft_split(line, ',');
	if (!colors || !colors[0] || !colors[1] || !colors[2])
		print_error("Invalid color format.\n");
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (!(r >= 0 && r <= 255) || !(g >= 0 && g <= 255) || !(b >= 0 && b <= 255))
		print_error("Invalid color range.\n");
	if (type == 'F')
		map->f_color = (r << 16) | (g << 8) | b;
	else if (type == 'C')
		map->c_color = (r << 16) | (g << 8) | b;
	else
		print_error("Invalid color type.\n");
	ft_free_split(colors); // TBI
}

/**
 * ft_strtrim: removes spaces/newline in string
 */
static void	parse_direction(t_map *map, char *line)
{
	char	*texture_path;

	texture_path = ft_strtrim(line + 3, " \n");
	if (!texture_path || open(texture_path, O_RDONLY) < 0)
		print_error("Invalid texture path.\n");
	if (ft_strncmp(line, "NO", 2) == 0)
		map->n_texture = texture_path;
	else if (ft_strncmp(line, "SO", 2) == 0)
		map->s_texture = texture_path;
	else if (ft_strncmp(line, "WE", 2) == 0)
		map->w_texture = texture_path;
	else if (ft_strncmp(line, "EA", 2) == 0)
		map->e_texture = texture_path;
	else
		print_error("Unknown direction.\n");
}

static void	process_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return ;
	if (ft_strncmp(line + i, "NO ", 3) == 0 || ft_strcmp(line + i, "SO ") == 0
		|| ft_strcmp(line + i, "WE ") == 0 || ft_strcmp(line + i, "EA ") == 0)
		parse_direction(&game->map, line + i);
	else if (ft_strncmp(line + i, "F ", 2) == 0 || ft_strncmp(line + i, "C ",
			2) == 0)
		parse_color(&game->map, line + i, line[0]);
	else if (line[0] == '1' || line[0] == '0')
		parse_grid(&game->map, line);
	else
		print_error("Invalid line in the map.\n");
}

static void	parse_grid(t_map *map, char *line)
{
	if (map->grid == NULL)
	{
		map->grid = (char **)ft_calloc(map->height, sizeof(char *));
		if (!map->grid)
			print_error("Failed to allocate memory for grid.\n");
	}
	map->grid[map->lcount] = ft_strdup(line);
	if (!map->grid[map->lcount])
		print_error("Failed to allocate memory for grid line.\n");
	ft_strncpy(map->grid[map->lcount], line, map->width);
	map->lcount++;
}

void	parse_map(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open file.\n");
	line = get_next_line(fd);
	while (line)
	{
		get_map_size(line, &game->map);
		process_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	validate_map(&game->map); // TBI
}
