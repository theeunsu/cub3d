/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:02:09 by eahn              #+#    #+#             */
/*   Updated: 2024/10/09 17:20:18 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* malloc, free, exit */
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
}			t_game;

void		print_error(char *message);