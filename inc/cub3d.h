

#ifndef CUB3D_H
# define CUB3D_H


# include "./MLX42/include/MLX42/MLX42.h"
#include "libft.h"

/* malloc, free, exit */
# include <stdlib.h>

/* open */

#include <fcntl.h>

#include <unistd.h>
#include <math.h>

#ifndef PI
#define PI 3.1415926535

#endif

# ifndef PI
#  define PI 3.1415926535
#  define INITIAL_LINES 10
#  define LINE_INCREMENT 5

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

void			print_error(char *message);

#endif
