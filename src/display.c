/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:53:09 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/25 11:37:55 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void player_rotation(t_game *game, int i)
{
    if (i == 1)
    {
        game->map.player.angle += 0.05;
        if (game->map.player.angle > 2 * PI)
            game->map.player.angle -= 2 * PI;
    }
    else
    {
        game->map.player.angle -= 0.05;
        if (game->map.player.angle < 0)
            game->map.player.angle += 2 * PI;
    }
}

static void	set_new_position(t_game *game)
{
	int	new_x;
	int	new_y;
	int	i;
	int	j;

	new_x = roundf(game->map.player.x + game->map.player.dx);
	new_y = roundf(game->map.player.y + game->map.player.dy);
	i = (new_x / TILE_SIZE);
	j = (new_y / TILE_SIZE);
	if (game->map.grid[j][i] != '1' && game->map.grid[j][game->map.player.x / TILE_SIZE] != '1' 
        && game->map.grid[game->map.player.y / TILE_SIZE][i] != '1')
	{
		game->map.player.y = new_x;
		game->map.player.x = new_y;
	}
}

static void	move_player(t_game *game)
{
	if (game->map.player.mov_u_d == -1)
	{
		game->map.player.dx *= -1;
		game->map.player.dy *= -1;
	}
	if (game->map.player.mov_l_r == 1)
	{
		game->map.player.dx = -sin(game->map.player.angle) * 4;
		game->map.player.dy = cos(game->map.player.angle) * 4;
	}
	if (game->map.player.mov_l_r == -1)
	{
		game->map.player.dx = sin(game->map.player.angle) * 4;
		game->map.player.dy = -cos(game->map.player.angle) * 4;
	}
	if (game->map.player.rotation == 1)
		player_rotation(game, 1);
	if (game->map.player.rotation == -1)
		player_rotation(game, 0);
	set_new_position(game);
}

void	display_update(void *param)
{
	t_game *game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	move_player(game);
    raycasting(game);
    mlx_image_to_window(game->mlx, game->img, 0, 0);
}
