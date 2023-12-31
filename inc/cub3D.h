/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:28:54 by anrodri2          #+#    #+#             */
/*   Updated: 2023/12/14 18:54:31 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* --- SYSTEM LIBS --- */
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

/* --- HEADER FILES --- */
# include "libft.h"
# include "mlx.h"

/* --- BOOLEAN --- */
# define TRUE 1
# define FALSE 0

/* --- WINDOW CONSTANTS --- */
# define RES_WIDTH 1920
# define RES_HEIGHT 1080
# define MAP_WIDTH 800
# define WIN_TITLE "Cub3D"

/* --- DISPLAY CONSTANTS --- */
# define WALLS_SIZE 64.0
# define FOV 60.0
# define SPEED_Y 0.5
# define SPEED_X 0.2
# define SPRINT_SPEED 2
# define ROTATE_SENS 2
# define MAP_OFFSET 20

/* --- PIXEL COLORS --- */
# define WHITE 0xFFFFFF
# define BROWN 0xB98A2D
# define BLACK 0x000000
# define RED 0xCC0000
# define BLUE 0x66BFF
# define GREEN 0x00FF00
# define MAP_COLOUR 0x330155

/* --- MLX EVENTS --- */
# define KEYPRESS 02
# define KEYRELEASE 03
# define DESTROY_WINDOW 17

/* --- KEY CODES --- */
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364
# define SHIFT 65505

/* --- ERROR CODES --- */
# define K_ERR_MALLOC 12

/* --- SPECIAL CODES --- */
# define K_N 999
# define K_S 9999
# define K_E 99999
# define K_W 999999

/* --- ERROR MESSAGES --- */
# define MSG_ERR_MALLOC "Memory allocation has failed. \x1B[0m\n\x1B[33mPlease\
 make sure enough memory is dedicated to the process.\n\x1B[0m"
# define MSG_ERR_1_ARG "Only 1 argument was entered. \x1B[0m\n\x1B[33mPlease\
 make sure to enter the map path as an argument.\n\x1B[0m"
# define MSG_ERR_MULTIPLE_ARGS "Multiple arguments were entered. \x1B[0m\n\x1B[33mPlease\
 make sure to enter the map path as an argument only.\n\x1B[0m"
# define MSG_ERR_FILE_MAP_NOT_FOUND "File was not found. \x1B[0m\n\x1B[33mPlease\
 make sure to enter the right map file path.\n\x1B[0m"
# define MSG_ERR_FILE_ACCESS "File was found but is not accessible. \x1B[0m\n\x1B[33mPlease\
 Make sure the right file permissions are set.\n\x1B[0m"
# define MSG_ERR_WRONG_ID "Error \x1B[0m\n\x1B[33m\
There's a wrong identifier in the configuration file.\n\x1B[0m"
# define MSG_ERR_CFG "Error \x1B[0m\n\x1B[33m\
There's too much information on a line of your configuration file.\n\x1B[0m"
# define MSG_ERR_COLOUR "Error \x1B[0m\n\x1B[33m\
An RGB value is incorrect, be sure to input \
3 values each between 0 and 255.\n\x1B[0m"
# define MSG_ERR_TEXTURE_FILE "Error \x1B[0m\n\x1B[33m\
A texture file can't be opened, make sure \
to enter the right map file path.\n\x1B[0m"
# define MSG_ERR_WRONG_EXT "A non .cub file was entered. \x1B[0m\n\x1B[33mPlease\
 make sure to only enter .cub files.\n\x1B[0m"
# define MSG_ERR_ILLEGAL_CHARS_MAP "Illegal characters were found in the map file. \x1B[0m\n\x1B[33mPlease\
 make sure to enter a valid map.\n\x1B[0m"
# define MSG_ERR_MAP_NOT_CLOSED "The map entered is not closed by walls. \x1B[0m\n\x1B[33mPlease\
 make sure to enter a valid map.\n\x1B[0m"
# define MSG_ERR_EMPTY_LINE "The map has an empty line. \x1B[0m\n\x1B[33mPlease\
 make sure to enter a valid map.\n\x1B[0m"
# define MSG_ERR_MULTIPLE_SPAWNS "Multiple spawn locations were found. \x1B[0m\n\x1B[33mPlease\
 make sure to only enter one spawn location.\n\x1B[0m"
# define MSG_ERR_CREATE_WIN "Window creation has failed. \x1B[0m\n\x1B[33mPlease\
 make sure all drivers are correctly installed.\n\x1B[0m"

/* --- STRUCTS --- */
typedef struct s_parsing
{
	char	*file_path;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		spawn_direction;
	int		spawn_pos[2];
	int		floor_color_rgb[3];
	int		ceiling_color_rgb[3];
	char	**map;
	int		map_max_x;
	int		map_max_y;
	char	**cfg;
	char	**file;
}	t_parsing;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir;
	char	side;
	int		sprint;
	int		forwards;
	int		backwards;
	int		left;
	int		right;
	int		rotating;
	int		rotating_left;
	int		rotating_right;
	int		map_x;
	int		map_y;
	int		horizontal;
	int		vertical;
}			t_player;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_vect
{
	t_point	point;
	double	dir;
}	t_vect;

typedef struct s_ray
{
	double	p_p_dist;
	double	angle_btw_ray;
	double	constant;
	t_point	p_p_center;
}		t_ray;

typedef struct s_texture
{
	void	*mlx;
	t_img	img;
	int		width;
	int		height;
}	t_texture;

typedef struct s_cub
{
	int			is_colision;
	t_parsing	parsing;
	t_mlx		mlx;
	int			map_ratio;
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	t_img		img;
	t_img		img_mapbg;
	t_player	player;
	t_ray		ray;
}	t_cub;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	colour;
	int	is_borderless;
	int	border_size;
	int	border_color;
}	t_rect;

typedef struct s_displayed_col
{
	int			x;
	int			y;
	t_texture	*texture;
}	t_displayed_col;

typedef struct s_ray_data
{
	double	angle;
	int		nmb;
}	t_ray_data;

typedef struct s_intersection
{
	t_point	coord;
	char	side;
}	t_intersection;

/* --- MAIN FUNCTIONS --- */
void	custom_exit(t_cub *cub, int exit_code);

/* --- PARSING --- */
int		parsing(t_cub *cub, int argc, char **argv);
int		parsing_file(t_cub *cub);
int		parse_cfg(t_cub *cub);
void	get_textures(char *dir, char *cfg, t_cub *cub);
int		get_colors(char *side, char *cfg, t_cub *cub);
int		file_exists_check(char *file);
void	get_cfg(t_cub *cub);
void	get_map(t_cub *cub, int i);
void	map_max_len(t_cub *cub);

/* --- MAP PARSING --- */
int		parsing_map(t_cub *cub);
int		parsing_map_loop(t_cub *cub);
void	check_diagonals(t_cub *cub);
# define POSSIBLE_CHARS "01NSEW \n"

/* --- MLX --- */
int		mlx_main(t_cub *cub);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		mlx_hooks(t_cub *cub);

/* --- SHAPES --- */
void	print_rect(t_img *img, t_rect *rect);

/* --- DISPLAY --- */
int		print_map(t_cub *cub);
void	print_mapbg(t_cub *cub);
void	find_player(t_cub *cub);
void	print_player(t_cub *cub);
void	textures_to_img(t_cub *cub);
char	*get_mlx_pxl(t_img *img, int x, int y);

/* --- RAY CASTING --- */
int		ray_casting_main(t_cub *cub);
void	init_ray_cast(t_cub *cub);
double	calc_wall_distance(t_cub *cub, t_point inter);
int		draw_walls(t_cub *cub, double wall_dist, \
		int ray_nmb, t_displayed_col *displayed_col);
int		move_player_3d(t_cub *cub);
void	find_smallest_dist(t_cub *cub, t_point walls, \
		t_displayed_col *displayed_col, t_ray_data ray);
int		check_wall(t_cub *cub, t_point inter);
double	increment_ray(t_cub *cub, t_intersection *inter, \
		t_point a, int *int_coord);
int		check_error_in_ray(t_cub *cub, t_intersection inter);
void	collision_animation(t_cub *cub);

/* --- TOOLS --- */
double	to_radians(double angle);
int		create_trgb(int t, int r, int g, int b);

#endif
