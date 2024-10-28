/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:21:42 by eahn              #+#    #+#             */
/*   Updated: 2024/10/28 18:43:41 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	safe_exit(t_game *game, char *message)
{
	if (game->tex)
		free_textures(game->tex);
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	if (game->rays)
		free(game->rays);
	printf("%s", message);
	free(game);
	exit(0);
}

void	free_textures(t_tex *tex)
{
	free(tex->no);
	free(tex->so);
	free(tex->we);
	free(tex->ea);
	free(tex);
}

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
		free(game);
		game = NULL;
	}
}
