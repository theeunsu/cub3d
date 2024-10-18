/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:28:59 by eahn              #+#    #+#             */
/*   Updated: 2024/10/18 16:42:28 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_args(int ac, char **av)
{
	if (ac != 2)
		print_error("Invalid number of arguments.\n");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		print_error("Invalid file extension.\n");
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", 0);
	// mlx_key_hook(game->win, key_handler, game);
	mlx_loop(game->mlx);
}



int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		print_error("Failed to allocate memory.\n");
	init_struct(game);
	check_args(ac, av);
	get_map(av[1], &game->map);
	parse_map(av[1], game);
	init_game(game);
	// free_game(game); 
	return (0);
}
