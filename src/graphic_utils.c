/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:32 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/26 19:21:17 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	set_angle(double angle)
{
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

int	wall_checker(t_game *game, float x, float y)
{
	int	x_grid;
	int	y_grid;

	if (x < 0 || y < 0)
		return (0);
	x_grid = floor(x / TILE_SIZE);
	y_grid = floor(y / TILE_SIZE);
	if (x_grid >= game->map.width || y_grid >= game->map.height)
		return (0);
	if (game->map.grid[y_grid][x_grid] == '1')
		return (0);
	return (1);
}

int	color_fix(int color)
{
	unsigned int	b;

	b = 0;
	b |= (color & 0x000000FF) << 24;
	b |= (color & 0x0000FF00) << 8;
	b |= (color & 0x00FF0000) >> 8;
	b |= (color & 0xFF000000) >> 24;
	return (b);
}

void	render_pixel(t_game *game, int x, int y, uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(game->img, x, y, color);
}
