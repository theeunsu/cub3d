/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:10:36 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/23 20:29:38 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assign_player(t_map *map, int *player_count, int i, int j)
{
	(*player_count)++;
	map->player.x = j + 0.5;
	map->player.y = i + 0.5;
	map->grid[i][j] = '0';
}

static void player_store_pos(char angle, t_map *map, int i, int j)
{
	if (angle == 'N')
		map->player.angle = 3 * PI / 2;
	if (angle == 'S')
		map->player.angle = PI / 2;
	if (angle == 'W')
		map->player.angle = PI;
	if (angle == 'E')
		map->player.angle = 0;
	map->player.x = (j * TILE_SIZE) + TILE_SIZE / 2;
	map->player.y = (i + TILE_SIZE) + TILE_SIZE / 2;
	map->player.dx = cos(map->player.angle);
	map->player.dy = -sin(map->player.angle);
	map->player.plane_x = i;
	map->player.plane_y = j;
	map->grid[i][j] = '0';
}

static void	check_player_chars(t_map *map)
{
	int		i;
	int		j;
	int		player_count;
	char	c;

	i = 0;
	player_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->grid[i][j];
			if (c != '1' && c != '0' && c != ' ' && c != 'N' && c != 'S'
				&& c != 'W' && c != 'E')
				print_error("Map contains invalid characters.\n");
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
				|| map->grid[i][j] == 'W' || map->grid[i][j] == 'E')
			{
				player_count++;
				player_store_pos(map->grid[i][j], map, i, j);
			}
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				assign_player(map, &player_count, i, j);
			j++;
		}
		i++;
	}
	if (player_count != 1)
		print_error("Map must contain exactly one player.\n");
}

// static void	check_player_chars(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	player_count;

// 	i = 0;
// 	player_count = 0;
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			if (map->grid[i][j] != '1' && map->grid[i][j] != '0'
// 				&& map->grid[i][j] != ' ' && map->grid[i][j] != 'N'
// 				&& map->grid[i][j] != 'S' && map->grid[i][j] != 'W'
// 				&& map->grid[i][j] != 'E')
// 				print_error("Map contains invalid characters.\n");
// 			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
// 				|| map->grid[i][j] == 'W' || map->grid[i][j] == 'E')
// 			{
// 				player_count++;
// 				map->player.x = j + 0.5;
// 				map->player.y = i + 0.5;
// 				map->grid[i][j] = '0';
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (player_count != 1)
// 		print_error("Map must contain exactly one player.\n");
// }

static void	check_position(t_map *map, int i, int j)
{
	if (i >= 0 && i < map->height && j >= 0 && j < map->width)
	{
		if (map->grid[i][j] != ' ' && map->grid[i][j] != '1')
			print_error("Map contains invalid space surroundings.\n");
	}
}

static void	check_empty_spaces(t_map *map, int i, int j)
{
	check_position(map, i - 1, j - 1);
	check_position(map, i - 1, j);
	check_position(map, i - 1, j + 1);
	check_position(map, i, j - 1);
	check_position(map, i, j + 1);
	check_position(map, i + 1, j - 1);
	check_position(map, i + 1, j);
	check_position(map, i + 1, j + 1);
}

// static void	check_empty_spaces(t_map *map, int i, int j)
// {
// 	int	offsets[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1},
// 			{1, 0}, {1, 1}};
// 	int	x;
// 	int	y;
// 	int	k;

// 	k = 0;
// 	while (k < 8)
// 	{
// 		x = i + offsets[k][0];
// 		y = j + offsets[k][1];
// 		if (x >= 0 && y >= 0 && x < map->height && y < map->width)
// 		{
// 			if (map->grid[x][y] != ' ' && map->grid[x][y] != '1')
// 				print_error("Map contains invalid space surroundings.\n");
// 		}
// 		k++;
// 	}
// }

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
