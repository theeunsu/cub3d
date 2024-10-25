/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:51:55 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/25 11:47:47 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_texture_t	*select_texture(t_game *game, int flag)
{
	mlx_texture_t	*tex;

	game->rays->ray_angle = set_angle(game->rays->ray_angle);
	if (flag == 1)
	{
		if (game->rays->ray_angle > 0 && game->rays->ray_angle < PI)
			tex = game->tex->so;
		else
			tex = game->tex->no;
	}
	else
	{
		if (game->rays->ray_angle > PI / 2 && game->rays->ray_angle < (3 * (PI
					/ 2)))
			tex = game->tex->ea;
		else
			tex = game->tex->we;
	}
}

static double	get_offset(t_game *game, mlx_texture_t *tex, int flag)
{
	double	offset;

	if (flag == 0)
		offset = (int)fmod(game->rays->v_y, TILE_SIZE) * tex->width / TILE_SIZE;
	else
		offset = (int)fmod(game->rays->h_x, TILE_SIZE) * tex->width / TILE_SIZE;
	return (offset);
}

static void	draw_walls(t_game *game, int wall_start, int wall_end,
		double wall_height)
{
	double			offset_x;
	double			offset_y;
	mlx_texture_t	*tex;
	uint32_t		*pixel_array;
	double			scale_factor;

	tex = select_texture(game, game->rays->flag);
	scale_factor = (double)tex->height / wall_height;
	pixel_array = (uint32_t *)tex->pixels;
	offset_x = get_offset(game, tex, game->rays->flag);
	offset_y = (wall_start - (HEIGHT / 2) + (wall_height / 2)) * scale_factor;
	if (offset_y < 0)
		offset_y = 0;
	while (wall_start < wall_end)
	{
		if (game->rays->index >= WIDTH || game->rays->index < 0
			|| wall_start >= HEIGHT || wall_start < 0)
			return ;
		mlx_pixel_put(game->img, game->rays->index, wall_start,
			color_fix(pixel_array[((int)offset_y * tex->width)
				+ (int)offset_x]));
		offset_y += scale_factor;
		wall_start++;
	}
}

static void	draw_f_c(t_game *game, int ray, int wall_start, int wall_end)
{
	int	i;

	i = wall_start;
	while (i < HEIGHT)
	{
		if (ray >= WIDTH || ray < 0 || i >= HEIGHT || i < 0)
			return ;
		mlx_put_pixel(game, ray, i, game->map.f_color);
		i++;
	}
	i = 0;
	while (i < wall_end)
	{
		if (ray >= WIDTH || ray < 0 || i >= HEIGHT || i < 0)
			return ;
		mlx_put_pixel(game, ray, i, game->map.c_color);
		i++;
	}
}

void	draw_game(t_game *game, int ray)
{
	double	wall_height;
	double	wall_start;
	double	wall_end;

	game->rays->distance *= cos(set_angle(game->rays->ray_angle
				- game->map.player.angle));
	wall_height = (TILE_SIZE / game->rays->distance) * (WIDTH / 2);
	tan(game->map.player.fov_radians / 2);
	wall_start = (HEIGHT / 2) + (wall_height / 2);
	wall_end = (HEIGHT / 2) - (wall_height / 2);
	if (wall_start > HEIGHT)
		wall_start = HEIGHT;
	if (wall_end < 0)
		wall_end = 0;
	game->rays->index = ray;
	draw_walls(game, wall_start, wall_end, wall_height);
	draw_f_c(game, ray, wall_start, wall_end);
}
