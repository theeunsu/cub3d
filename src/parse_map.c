/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:27:25 by eahn              #+#    #+#             */
/*   Updated: 2024/10/18 17:43:00 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_rgb(char **line)
{
	int	rgb;

	while (ft_isspace(**line))
		(*line)++;
	rgb = ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	while (ft_isspace(**line) || **line == ',')
		(*line)++;
	return (rgb);
}

static void	assign_color(int *color, int r, int g, int b, char *str)
{
	if (*color != -1)
		print_error(str);
	*color = (r << 16 | g << 8 | b);
}

static void	parse_color(t_map *map, char *line, char type)
{
	int	r;
	int	g;
	int	b;

	line += 2;
	while (ft_isspace(*line))
		line++;
	r = extract_rgb(&line);
	g = extract_rgb(&line);
	b = extract_rgb(&line);
	if (!(r >= 0 && r <= 255) || !(g >= 0 && g <= 255) || !(b >= 0 && b <= 255))
		print_error("RGB values must be between 0 ad 255.\n");
	if (type == 'F')
		assign_color(&map->f_color, r, g, b, "Floor color already set.\n");
	else if (type == 'C')
		assign_color(&map->c_color, r, g, b, "Ceiling color already set.\n");
	else
		print_error("Invalid color type.\n");
	printf("f_color: %d, c_color: %d\n", map->f_color, map->c_color);
}

/**
 * ft_strtrim: removes spaces/newline in string
 */
static void	parse_direction(t_map *map, char *line)
{
	char	*texture_path;
	char	*trimmed_path;

	texture_path = line + 3;
	while (ft_isspace(*texture_path))
		texture_path++;
	trimmed_path = ft_strtrim(texture_path, "\n");
	// printf("texture_path: %s\n", trimmed_path);
	if (!trimmed_path || open(trimmed_path, O_RDONLY) < 0)
	{
		free(trimmed_path);
		print_error("Invalid texture path.\n");
	}
	if (ft_strncmp(line, "NO", 2) == 0)
		map->n_texture = trimmed_path;
	else if (ft_strncmp(line, "SO", 2) == 0)
		map->s_texture = trimmed_path;
	else if (ft_strncmp(line, "WE", 2) == 0)
		map->w_texture = trimmed_path;
	else if (ft_strncmp(line, "EA", 2) == 0)
		map->e_texture = trimmed_path;
	else
	{
		free(trimmed_path);
		print_error("Unknown direction.\n");
	}
	free(trimmed_path);
}

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
	// map->grid[map->lcount][map->width] = '\0';
	line_length = strlen(line);
	if (line_length < map->width)
		ft_memset(map->grid[map->lcount] + line_length, ' ', map->width
			- line_length);
	printf("grid: %s\n", map->grid[map->lcount]);
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
	if (temp_width > 0)
	{
		if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
		{
			if (temp_width > map->width)
				map->width = temp_width;
			map->height++;
		}
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
	{
		// printf("line: %s\n", line);
		process_line(line, game);
		// free(line);
	}
	validate_map(&game->map);
	close(fd);
}
