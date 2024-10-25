/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:27:25 by eahn              #+#    #+#             */
/*   Updated: 2024/10/25 18:10:11 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_data(t_map *map)
{
	if (!map->n_texture || !map->s_texture || !map->w_texture
		|| !map->e_texture)
		print_error("Missing texture data (NO, SO, WE, EA).\n");
	if (map->f_color == -1 || map->c_color == -1)
		print_error("Missing color data (F, C).\n");
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
	line_length = strlen(line);
	if (line_length < map->width)
		ft_memset(map->grid[map->lcount] + line_length, ' ', map->width
			- line_length);
	map->lcount++;
}

static void	process_line(char *line, t_game *game)
{
	char	*t_line;

	t_line = ft_strtrim(line, "\n");
	if (t_line[0] == '\0')
	{
		free(t_line);
		return ;
	}
	if (ft_strncmp(t_line, "NO ", 3) == 0 || ft_strncmp(t_line, "SO ", 3) == 0
		|| ft_strncmp(t_line, "WE ", 3) == 0 || ft_strncmp(t_line, "EA ",
			3) == 0)
		parse_direction(&game->map, t_line);
	else if (ft_strncmp(t_line, "F ", 2) == 0 || ft_strncmp(t_line, "C ",
			2) == 0)
		parse_color(&game->map, t_line, t_line[0]);
	else if (t_line[0] == '1' || t_line[0] == '0' || t_line[0] == ' ')
		parse_grid(&game->map, t_line);
	// free(t_line);
	return ;
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
		process_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	validate_data(&game->map);
	validate_map(&game->map);
	close(fd);
}
