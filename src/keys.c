/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:55:31 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/25 16:29:06 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void key_release(mlx_key_data_t keydata, t_game *game)
{
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
        game->map.player->mov_u_d = 0;
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
        game->map.player->mov_u_d = 0;
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
        game->map.player->mov_l_r = 0;
    else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
        game->map.player->mov_l_r = 0;
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
        game->map.player->rotation = 0;
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
        game->map.player->rotation = 0;
}

void key_handler(mlx_key_data_t keydata, void *param)
{
    t_game	*game;

    game = (t_game *)param;
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        game->map.player->mov_u_d = 1;
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        game->map.player->mov_u_d = -1;
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        game->map.player->mov_l_r = -1;
    else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        game->map.player->mov_l_r = 1;
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
        game->map.player->rotation = -1;
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
        game->map.player->rotation = 1;
    else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        // ft_exit(game); //to be done
    key_release(keydata, game);
}
