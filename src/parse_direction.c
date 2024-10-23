/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:00:15 by eahn              #+#    #+#             */
/*   Updated: 2024/10/22 21:24:25 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * ft_strtrim: removes spaces/newline in string
 */
void	parse_direction(t_map *map, char *line)
{
	char	*texture_path;
	char	*trimmed_path;

	texture_path = line + 3;
	while (ft_isspace(*texture_path))
		texture_path++;
	trimmed_path = ft_strtrim(texture_path, " \n");
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