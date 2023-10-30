/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:28:54 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/25 18:29:27 by anrodri2         ###   ########.fr       */
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

/* --- HEADER FILES --- */
# include "libft.h"
# include "mlx.h"

/* --- BOOLEAN --- */
# define TRUE 1
# define FALSE 0

/* --- WINDOW CONSTANTS --- */
# define RES_WIDTH 960
# define RES_HEIGHT 540
# define WIN_TITLE "Cub3D"

/* --- DISPLAY CONSTANTS --- */
# define ZOOM 20
# define PLAYER_SIZE 11
# define WALLS_SIZE 64
# define FOV 60
# define PLAYER_HEIGHT (WALLS_SIZE / 2)

/* --- PIXEL COLORS --- */
# define WHITE 0xFFFFFF
# define BROWN 0x663300
# define BLACK 0x000000
# define RED 0xCC0000

/* --- MLX EVENTS --- */
# define KEYPRESS 02

/* --- KEY CODES --- */
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

/* --- COLORS --- */
# define K_NORMAL "\x1B[0m"
# define K_RED "\x1B[31m"
# define K_GREEN "\x1B[32m"
# define K_YELLOW "\x1B[33m"
# define K_BLUE "\x1B[34m"
# define K_WHITE "\x1B[37m"

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
Make sure to enter the right map file path.\n\x1B[0m"
 # define MSG_ERR_FILE_ACCESS "File was found but is not accessible. \x1B[0m\n\x1B[33mPlease\
 Make sure the right file permissions are set.\n\x1B[0m"
# define MSG_ERR_WRONG_ID "Error \x1B[0m\n\x1B[33m\
There's a wrong identifier in the configuration file.\n\x1B[0m"
# define MSG_ERR_CFG "Error \x1B[0m\n\x1B[33m\
There's too much information on a line of your configuration file.\n\x1B[0m"
# define MSG_ERR_COLOUR "Error \x1B[0m\n\x1B[33m\
An RGB value is incorrect, be sure to input 3 values each between 0 and 255.\n\x1B[0m"
# define MSG_ERR_TEXTURE_FILE "Error \x1B[0m\n\x1B[33m\
A texture file can't be opened, make sure to enter the right map file path.\n\x1B[0m"
# define MSG_ERR_WRONG_EXT "A non .cub file was entered. \x1B[0m\n\x1B[33mPlease\
 make sure to only enter .cub files.\n\x1B[0m"
# define MSG_ERR_ILLEGAL_CHARS_MAP "Illegal characters were found in the map file. \x1B[0m\n\x1B[33mPlease\
 make sure to enter a valid map.\n\x1B[0m"
# define MSG_ERR_MAP_NOT_CLOSED "The map entered is not closed by walls. \x1B[0m\n\x1B[33mPlease\
 make sure to enter a valid map.\n\x1B[0m"
# define MSG_ERR_END_OF_LINE_IN_MAP "The map entered is not closed by walls. \x1B[0m\n\x1B[33mPlease\
 make sure to enter a valid map.\n\x1B[0m"
# define MSG_ERR_EMPTY_LINE "The map has an empty line. \x1B[0m\n\x1B[33mPlease\
 make sure to enter a valid map.\n\x1B[0m"
# define MSG_ERR_NO_SEP_CFG_MAP "There is no new line between the configuration part and the map. \x1B[0m\n\x1B[33mPlease\
 make sure to have an empty line between the configuration part and the map.\n\x1B[0m"
# define MSG_ERR_MULTIPLE_SPAWNS "Multiple spawn locations were found. \x1B[0m\n\x1B[33mPlease\
 make sure to only enter one spawn location.\n\x1B[0m"
# define MSG_ERR_MLX_INIT "Mlx initialisation has failed. \x1B[0m\n\x1B[33mPlease\
 make sure it is correctly installed.\n\x1B[0m"
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
	char 	**cfg;
	char	**file;
}	t_parsing;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_player
{
	int		x;
	int 	y;
	int 	dir;
	char 	side;
	int 	horizontal;
	int 	vertical;
}				t_player;

typedef struct s_vect
{
	int x;
	int y;
	int dir;
};

typedef struct s_cub
{
    t_parsing	parsing;
    t_mlx		mlx;
    t_img       img;
	t_player	player;
}	t_cub;

/* --- MAIN FUNCTIONS --- */
void	custom_exit(t_cub *cub, int exit_code);

/* --- PARSING --- */
int		parsing(t_cub *cub, int argc, char **argv);
int		parsing_file(t_cub *cub);
int		parse_cfg(t_cub *cub);
void	get_textures(char *dir, char *cfg, t_cub *cub);
int 	get_colors(char *side, char *cfg, t_cub *cub);
int		file_exists_check(char *file);
void	get_cfg(t_cub *cub);
void	get_map(t_cub *cub, int	i);

/* --- MAP PARSING --- */
int		parsing_map(t_cub *cub);
int		parsing_map_loop(t_cub *cub);
# define POSSIBLE_CHARS "01NSEW \n"

/* --- MLX --- */
int		mlx_main(t_cub *cub);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int     mlx_hooks(t_cub *cub);

/* --- DISPLAY --- */
int		print_map(t_cub *cub);
void	find_player(t_cub *cub);
void	move_player(t_cub *cub);


#endif
