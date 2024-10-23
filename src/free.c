/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:21:42 by eahn              #+#    #+#             */
/*   Updated: 2024/10/23 17:03:38 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	if (game->map.grid)
	{
		while (i < game->map.height)
		{
			if (game->map.grid[i])
			{
				free(game->map.grid[i]);
				game->map.grid[i] = NULL;
			}
			i++;
		}
		free(game->map.grid);
		game->map.grid = NULL;
		// free_map (&game->map);
		// free(game->mlx);
		free(game);
		game = NULL;
	}
}
