

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "libft.h"

/* malloc, free, exit */
# include <stdlib.h>

/* open */

# include <fcntl.h>
# include <math.h>
# include <unistd.h>

#include <stdio.h>

# ifndef PI
#  define PI 3.1415926535
# endif

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 960
# endif

typedef struct s_img
{
	void		*img_ptr;
}				t_img;

typedef struct s_map
{
	int			width;
	int			height;
	int lcount;  // map line count
	char **grid; // 2D array
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	int			f_color;
	int			c_color;
}				t_map;

typedef struct s_player
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	float plane_x; // TBD
	float plane_y; // TBD
	float angle;   // TBD
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
}				t_game;

void	get_map(char *file, t_map *map);

/* check_map.c */
void	validate_map(t_map *map);

/* free.c */
void	free_game(t_game *game);
void	ft_free_split(char **split);

/* init.c */
void			init_struct(t_game *game);

/* parse_map.c */
void			parse_map(char *file, t_game *game);

/* utils.c */
void			get_map_size(char *line, t_map *map);
void			print_error(char *message);

#endif
