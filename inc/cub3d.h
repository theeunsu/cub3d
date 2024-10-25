

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "libft.h"

/* malloc, free, exit */
# include <stdlib.h>

/* open */

# include <fcntl.h>
# include <math.h>
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

// typedef struct s_list_tex
// {
// 	char				*tex;
// 	char				*val;
// 	struct s_list_tex	*next;
// }						t_list_tex;

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
	double			dx;
	double			dy;
	int rotation; // use it?
	int mov_l_r;  // left right movement
	int mov_u_d;  // up down movement
	double			angle;
	float			fov_radians;
}					t_player;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_map
{
	int				width;
	int				height;
	int lcount;  // map line count
	char **grid; // 2D array

	char			*n_texture;
	char			*s_texture;
	char			*w_texture;
	char			*e_texture;
	int				f_color;
	int				c_color;
	int				player_count;
	t_rgb			rgb;
	t_player		*player;
}					t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_map			map;
	t_ray			*rays;
	t_tex			*tex;
	// t_list_tex			*list_tex;
}					t_game;

/* display.c */
void				display_update(void *param);

/* draw.c */
void				draw_game(t_game *game, int ray);

/* graphic utils.c */
int					color_fix(int color);
int					wall_checker(t_game *game, float x, float y);
float				set_angle(double angle);

/* free.c */
void				free_game(t_game *game);

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
