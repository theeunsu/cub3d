/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:28:59 by eahn              #+#    #+#             */
/*   Updated: 2024/10/28 15:30:25 by smiranda         ###   ########.fr       */
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

static void	init_struct(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	game->map.f_color = -1;
	game->map.c_color = -1;
	game->rays = ft_calloc(sizeof(t_ray), WIDTH);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		print_error("Failed to allocate memory.\n");
	init_struct(game);
	check_args(ac, av);
	get_map(av[1], &game->map);
	parse_map(av[1], game);
	// while (i < game->map.height)
	// {
	// 	printf("%s\n", game->map.grid[i]);
	// 	i++;
	// }
	printf("f_color: %d\n", game->map.f_color);
	start_game(game);
	free_game(game);
	system("leaks --list -- cub3D");
	return (0);
}
