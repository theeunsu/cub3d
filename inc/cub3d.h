/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:02:09 by eahn              #+#    #+#             */
/*   Updated: 2024/10/11 16:47:40 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"

/* malloc, free, exit */
#include <stdlib.h>

/* open */
#include <fcntl.h>

#include <unistd.h>


typedef struct s_img
{
	
} t_img;

typedef struct s_map
{
	int width;
	int height;
	char **grid; // 2D array
} t_map;

typedef struct s_player
{
	int x;
	int y;		
} t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	t_player player;
}			t_game;

void		print_error(char *message);

#endif