/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:10:36 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/12 18:14:28 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	get_map(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open file.\n");
	line = get_next_line(fd);
	if (!line)
		print_error("Empty file.\n");
	game->map_line = sl_strdup(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			game->map_line = sl_strjoin(game->map_line, line);
			free(line);
		}
	}
	close(fd);
}

static void	valid_components(t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->map_line))
	{
		if (game->map_line[i] != ' ' && game->map_line[i] != '1'
			&& game->map_line[i] != '0' && game->map_line[i] != 'N'
			&& game->map_line[i] != 'S' && game->map_line[i] != 'E'
			&& game->map_line[i] != 'W')
			print_error("Invalid map.\n");
		i++;
	}
}

void	read_map(char *file, t_game *game)
{
    get_map(file, &game);
    valid_components(&game);
}
