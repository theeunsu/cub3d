/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:10:36 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/16 00:19:09 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_walls(t_map *map)
{
}

void	validate_map(t_map *map)
{
	check_walls(map);        // TBI
	check_empty_spaces(map); // TBI
	check_player(map);       // TBI
	check_valid_chars(map);  // TBI
	check_map_size(map);     // TBI
}
