/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:14:44 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/22 21:20:23 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->dx = 0;
	player->dy = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->angle = 0;
}

static void	init_img(t_img *img)
{
	img->img_ptr = NULL;
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
	game->win = NULL;
	init_map(&game->map);
	init_img(&game->img);
	init_player(&game->map.player);
}
