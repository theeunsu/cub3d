/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:51:55 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/26 19:07:10 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_draw_wall_params
{
	double				offset_x;
	double				offset_y;
	mlx_texture_t		*tex;
	uint32_t			*pixel_array;
	double				scale_factor;
	int					wall_end;
}						t_draw_wall_params;

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
		if (game->rays->ray_angle > PI / 2
			&& game->rays->ray_angle < (3 * (PI / 2)))
			tex = game->tex->ea;
		else
			tex = game->tex->we;
	}
	return (tex);
}

static double	get_offset(t_game *game, mlx_texture_t *tex, int flag)
{
	double	offset;

	if (flag == 1)
		offset = fmod(game->rays->h_x, TILE_SIZE) * (tex->width / TILE_SIZE);
	else
		offset = fmod(game->rays->v_y, TILE_SIZE) * (tex->width / TILE_SIZE);
	return (offset);
}

static void	draw_walls(t_game *game, double wall_start, double wall_end,
		double wall_height)
{
	t_draw_wall_params	params;
	int					texture_y;
	int					texture_x;
	uint32_t			color;

	params.tex = select_texture(game, game->rays->flag);
	params.scale_factor = (double)params.tex->height / wall_height;
	params.pixel_array = (uint32_t *)params.tex->pixels;
	params.offset_x = get_offset(game, params.tex, game->rays->flag);
	params.offset_y = (wall_end - (HEIGHT / 2) + (wall_height / 2))
		* params.scale_factor;
	if (params.offset_y < 0)
		params.offset_y = 0;
	while (wall_end < wall_start)
	{
		texture_y = (int)params.offset_y % params.tex->height;
		texture_x = (int)params.offset_x % params.tex->width;
		color = params.pixel_array[texture_y * params.tex->width + texture_x];
		render_pixel(game, game->rays->index, wall_end, color_fix(color));
		params.offset_y += params.scale_factor;
		wall_end++;
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
		mlx_put_pixel(game->img, ray, i, game->map.f_color);
		i++;
	}
	i = 0;
	while (i < wall_end)
	{
		if (ray >= WIDTH || ray < 0 || i >= HEIGHT || i < 0)
			return ;
		mlx_put_pixel(game->img, ray, i, game->map.c_color);
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
	wall_height = (TILE_SIZE / game->rays->distance) * (WIDTH / 2)
		/ tan(game->map.player.fov_radians / 2);
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
