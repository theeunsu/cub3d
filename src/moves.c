/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:53:09 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/23 22:35:26 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void display_update(void *param)
{
    t_game *game;

    game = (t_game *)param;
    mlx_delete_image(game->mlx, game->img);
}