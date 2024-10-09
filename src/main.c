/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:28:59 by eahn              #+#    #+#             */
/*   Updated: 2024/10/09 17:19:40 by eahn             ###   ########.fr       */
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


int main (int ac, char **av)
{
    t_game *game;

    check_args (ac, av);
    read_map(av[1]);
    
}