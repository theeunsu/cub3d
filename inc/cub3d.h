/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:02:57 by eahn              #+#    #+#             */
/*   Updated: 2024/10/28 19:03:23 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

/* malloc, free, exit */
# include <stdlib.h>

/* open */

# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

# define PI 3.1415926535
# define WIDTH 1280
# define HEIGHT 960
# define TILE_SIZE 30
# define FOV 60
# define SPEED 4

typedef struct s_tex
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}					t_tex;

typedef struct s_ray
{
	int				index;
	double			ray_angle;
	double			h_x;
	double			h_y;
	double			v_x;
	double			v_y;
	double			distance;
	int				flag;
}					t_ray;

typedef struct s_player
{
	int				x;
	int				y;
	int				rotation;
	int				mov_l_r;
	int				mov_u_d;
	double			angle;
	float			fov_radians;
}					t_player;

typedef struct s_rgb
{
	uint32_t		r;
	uint32_t		g;
	uint32_t		b;
}					t_rgb;

typedef struct s_map
{
	int				width;
	int				height;
	int				lcount;
	char			**grid;
	char			*n_texture;
	char			*s_texture;
	char			*w_texture;
	char			*e_texture;
	int32_t			f_color;
	int32_t			c_color;
	int				player_count;
	t_rgb			rgb;
	t_player		player;
}					t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_map			map;
	t_ray			*rays;
	t_tex			*tex;
}					t_game;

/* display.c */
void				display_update(void *param);

/* draw.c */
void				draw_game(t_game *game, int ray);

/* graphic utils.c */
int					color_fix(int color);
int					wall_checker(t_game *game, float x, float y);
float				set_angle(double angle);
void				render_pixel(t_game *game, int x, int y, uint32_t color);

/* free.c */
void				free_game(t_game *game);
void				safe_exit(t_game *game, char *message);
void				free_textures(t_tex *tex);

/* parse_map.c */
void				parse_map(char *file, t_game *game);

/* raycasting.c */
void				raycasting(t_game *game);

/* validate_map.c */
void				validate_map(t_map *map);

/* parse_direction.c */
void				parse_direction(t_map *map, char *line);

/* parse_color.c */
void				parse_color(t_map *map, char *line, char type);

/* start_game.c */
void				start_game(t_game *game);

/* utils.c */
void				get_map_size(char *line, t_map *map);
void				print_error(char *message);
void				get_map(char *file, t_map *map);
void				*safe_malloc(size_t size);

/* keys.c */
void				key_handler(mlx_key_data_t keydata, void *param);

/* display.c */
void				display_update(void *param);

#endif
