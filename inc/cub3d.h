/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:02:09 by eahn              #+#    #+#             */
/*   Updated: 2024/10/12 18:00:40 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* malloc, free, exit */
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef PI
#define PI 3.1415926535

#endif


typedef struct s_game
{
	void	*mlx;
	float	x;
	float	y;
	float dx;
	float dy;
	float angle;
	char* map_line;
	void	*win;
}			t_game;

void		print_error(char *message);