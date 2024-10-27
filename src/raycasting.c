/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:35:24 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/26 20:34:26 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	intersection(float angle, float *inter, float *step, int is_h)
{
	if (is_h)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (angle < 0.5 * PI || angle > 1.5 * PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

static int	angle_checker(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (PI / 2) && angle < (3 * PI / 2))
			return (1);
	}
	return (0);
}

static float	vertical_intersection(t_game *game, float angle)
{
	float	x;
	float	y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angle);
	x = floor(game->map.player.x / TILE_SIZE) * TILE_SIZE;
	pixel = intersection(angle, &x, &x_step, 0);
	y = game->map.player.y + (x - game->map.player.x) * tan(angle);
	if ((angle_checker(angle, 'x') && y_step < 0) || (!angle_checker(angle, 'x')
			&& y_step > 0))
		y_step *= -1;
	while (wall_checker(game, x - pixel, y))
	{
		x += x_step;
		y += y_step;
	}
	game->rays->v_x = x;
	game->rays->v_y = y;
	return (sqrt(pow(y - game->map.player.y, 2) + pow(x - game->map.player.x,
				2)));
}

static float	horizontal_intersection(t_game *game, float angle)
{
	float	x;
	float	y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE / tan(angle);
	y_step = TILE_SIZE;
	y = floor(game->map.player.y / TILE_SIZE) * TILE_SIZE;
	pixel = intersection(angle, &y, &y_step, 1);
	x = game->map.player.x + (y - game->map.player.y) / tan(angle);
	if ((angle_checker(angle, 'y') && x_step > 0) || (!angle_checker(angle, 'y')
			&& x_step < 0))
		x_step *= -1;
	while (wall_checker(game, x, y - pixel))
	{
		x += x_step;
		y += y_step;
	}
	game->rays->h_x = x;
	game->rays->h_y = y;
	return (sqrt(pow(y - game->map.player.y, 2) + pow(x - game->map.player.x,
				2)));
}

void	raycasting(t_game *game)
{
	double	h_vector;
	double	v_vector;
	int		ray;

	ray = 0;
	game->rays->ray_angle = game->map.player.angle
		- (game->map.player.fov_radians / 2);
	while (ray < WIDTH)
	{
		game->rays->flag = 0;
		h_vector = horizontal_intersection(game,
				set_angle(game->rays->ray_angle));
		v_vector = vertical_intersection(game,
				set_angle(game->rays->ray_angle));
		if (h_vector <= v_vector)
		{
			game->rays->distance = h_vector;
			game->rays->flag = 1;
		}
		else
			game->rays->distance = v_vector;
		draw_game(game, ray);
		ray++;
		game->rays->ray_angle += (game->map.player.fov_radians / WIDTH);
	}
}
