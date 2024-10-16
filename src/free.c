/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:21:42 by eahn              #+#    #+#             */
/*   Updated: 2024/10/16 17:18:53 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.grid)
	{
		while (i < game->map.lcount)
		{
			free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	free(game->map.n_texture);
	free(game->map.s_texture);
	free(game->map.w_texture);
	free(game->map.e_texture);
	free(game);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
