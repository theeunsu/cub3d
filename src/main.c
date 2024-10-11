/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:28:59 by eahn              #+#    #+#             */
/*   Updated: 2024/10/11 16:48:19 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void check_args (int ac, char **av)
{
    if (ac != 2)
        print_error("Invalid number of arguments.\n");
    if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
        print_error("Invalid file extension.\n");
}


void parse_map(char *file, t_game *game)
{
    int fd;
    int ret;
    char *line;
    

    fd = open(file, O_RDONLY);
    if (fd < 0)
        print_error("Failed to open file.\n");
    fd = get_next_line(fd, &line);
    while (fd > 0)
    {
        if (ft_strncmp(line, "NO ", 3) == 0 || ft_strcmp(line, "SO ") == 0 || ft_strcmp(line, "WE ") == 0 || ft_strcmp(line, "EA ") == 0)
            parse_direction(&game->map, line); // TBI
        else if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
            parse_color(&game->map, line, line[0]); // TBI
        else
            parse_map_grid(&game->map, &game->player, line); // TBI
        free(line);
        ret = get_next_line(fd, &line);
    }
    close(fd);
}

void init_struct(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->img.space = NULL;
    game->img.wall = NULL;
    game->img.player = NULL;
    game->img.exit = NULL;
    game->img.collec = NULL;
    game->map.width = 0;
    game->map.height = 0;
    game->map.grid = NULL;
}


int main (int ac, char **av)
{
    t_game game;

    check_args (ac, av);
    init_struct(&game);
    parse_map(av[1], &game);
}