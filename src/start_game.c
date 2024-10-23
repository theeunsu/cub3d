/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:30:53 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/23 19:37:57 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_texture(t_game *game)
{
    
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", 0);
	if (!game->mlx)
		print_error("Failed to initialize mlx.\n");
	if (!init_texture(game))
		print_error("Failed to initialize textures.\n");
	
	mlx_loop(game->mlx);
}

