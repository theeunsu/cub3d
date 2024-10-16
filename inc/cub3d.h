

#ifndef CUB3D_H
# define CUB3D_H

# include "./MLX42/include/MLX42/MLX42.h"
#include "libft.h"

/* malloc, free, exit */
#include <stdlib.h>

/* open */
#include <fcntl.h>

#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#ifndef PI
#define PI 3.1415926535

#endif



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
	float	x;
	float	y;
	float dx;
	float dy;
	float angle;
	char* map_line;
	void	*win;
	t_img	img;
	t_map	map;
	t_player player;
}			t_game;

void		print_error(char *message);

#endif