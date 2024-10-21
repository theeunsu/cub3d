/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:10:36 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/21 16:12:06 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_data(t_map *map)
{
	if (!map->n_texture || !map->s_texture || !map->w_texture
		|| !map->e_texture)
		print_error("Missing texture data (NO, SO, WE, EA).\n");
	if (map->f_color == -1 || map->c_color == -1)
		print_error("Missing color data (F, C).\n");
}

static void	check_player_chars(t_map *map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] != '1' && map->grid[i][j] != '0'
				&& map->grid[i][j] != ' ' && map->grid[i][j] != 'N'
				&& map->grid[i][j] != 'S' && map->grid[i][j] != 'W'
				&& map->grid[i][j] != 'E')
				print_error("Map contains invalid characters.\n");
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
				|| map->grid[i][j] == 'W' || map->grid[i][j] == 'E')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		print_error("Map must contain exactly one player.\n");
}

static void	check_empty_spaces(t_map *map, int i, int j)
{
	int	offsets[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1},
			{1, 0}, {1, 1}};
	int	x;
	int	y;
	int	k;

	k = 0;
	while (k < 8)
	{
		x = i + offsets[k][0];
		y = j + offsets[k][1];
		if (x >= 0 && y >= 0 && x < map->height && y < map->width)
		{
			if (map->grid[x][y] != ' ' && map->grid[x][y] != '1')
				print_error("Map contains invalid space surroundings.\n");
		}
		k++;
	}
}

void	validate_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
			{
				if (map->grid[i][j] != '1' && map->grid[i][j] != ' ')
					print_error("Map is not surrounded by walls.\n");
			}
			else if (map->grid[i][j] == ' ')
				check_empty_spaces(map, i, j);
			j++;
		}
		i++;
	}
	check_player_chars(map);
}
