/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:14:44 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/25 10:34:09 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_player *player)
{
	player = malloc(sizeof(t_player));
	if (!player)
		print_error("Failed to allocate memory for player.\n");
	player->x = 0;
	player->y = 0;
	player->dx = 0;
	player->dy = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->angle = 0;
	player->rotation = 0;
	player->mov_l_r = 0;
	player->mov_u_d = 0;
}

// static void	init_img(mlx_image_t *img)
// {
// 	img->
// }

static void init_raycast(t_ray *rays)
{
	rays = malloc(sizeof(t_ray));
		if (!rays)
			print_error("Failed to allocate memory for rays.\n");
	rays->ray_angle = 0;
	rays->h_x = 0;
	rays->h_y = 0;
	rays->v_x = 0;
	rays->v_y = 0;
	rays->distance = 0;
	rays->flag = 0;
	rays->index = 0;
}

static void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->lcount = 0;
	map->grid = NULL;
	map->n_texture = NULL;
	map->s_texture = NULL;
	map->w_texture = NULL;
	map->e_texture = NULL;
	map->f_color = -1;
	map->c_color = -1;
}

void	init_struct(t_game *game)
{
	game->mlx = NULL;
	init_map(&game->map);
	// init_img(&game->img);
	init_player(&game);
	init_raycast(&game->rays);
}
