/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:00:15 by eahn              #+#    #+#             */
/*   Updated: 2024/10/26 21:19:01 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*trim_path(char *line)
{
	char	*path;

	path = line + 3;
	while (*path && ft_isspace(*path))
		path++;
	return (ft_strtrim(path, " "));
}

static void	assign_texture(t_map *map, char *line, char *t_path)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		map->n_texture = t_path;
	else if (ft_strncmp(line, "SO", 2) == 0)
		map->s_texture = t_path;
	else if (ft_strncmp(line, "WE", 2) == 0)
		map->w_texture = t_path;
	else if (ft_strncmp(line, "EA", 2) == 0)
		map->e_texture = t_path;
	else
	{
		free(t_path);
		print_error("Unknown direction.\n");
	}
}

void	parse_direction(t_map *map, char *line)
{
	char	*t_path;
	int		fd;

	t_path = trim_path(line);
	fd = open(t_path, O_RDONLY);
	if (fd < 0)
	{
		free(t_path);
		print_error("Invalid texture path. Failed to open file.\n");
	}
	assign_texture(map, line, t_path);
	printf("Assigned textures:\n");
	printf("game->map.n_texture: %s\n", map->n_texture);
	printf("game->map.s_texture: %s\n", map->s_texture);
	printf("game->map.w_texture: %s\n", map->w_texture);
	printf("game->map.e_texture: %s\n", map->e_texture);
	// free(t_path);
	close(fd);
}
