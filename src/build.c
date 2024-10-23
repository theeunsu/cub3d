/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:53:09 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/23 18:20:26 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_forward(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_back(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		look_left(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		look_right(game);
}

void	move_forward(t_game *game)
{
	game->x += game->dx;
	game->y += game->dy;
}

void	move_back(t_game *game)
{
	game->x -= game->dx;
	game->y -= game->dy;
}

void	look_left(t_game *game)
{
	game->angle -= 0.1;
	if (game->angle < 0)
		game->angle += 2 * PI;
	game->dx = cos(game->angle) * 5;
	game->dy = sin(game->angle) * 5;
}

void	look_right(t_game *game)
{
	game->angle += 0.1;
	if (game->angle > 2 * PI)
		game->angle -= 2 * PI;
	game->dx = cos(game->angle) * 5;
	game->dy = sin(game->angle) * 5;
}
