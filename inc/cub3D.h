/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:28:54 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/18 15:55:38 by anrodri2         ###   ########.fr       */
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

/* --- HEADER FILES --- */
# include "libft.h"
# include "mlx.h"

/* --- BOOLEAN --- */
# define TRUE 1
# define FALSE 0

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
 make sure to enter the right map file path.\n\x1B[0m"
# define MSG_ERR_FILE_ACCESS "File was found but is not accessible. \x1B[0m\n\x1B[33mPlease\
 make sure the right file permissions are set.\n\x1B[0m"
# define MSG_ERR_WRONG_EXT "A non .cub file was entered. \x1B[0m\n\x1B[33mPlease\
 make sure to only enter .cub files.\n\x1B[0m"
 # define MSG_ERR_ILLEGAL_CHARS_MAP "Illegal characters were found in the map file. \x1B[0m\n\x1B[33mPlease\
 make sure to enter a valid map.\n\x1B[0m"

/* --- STRUCTS --- */
typedef struct s_parsing
{
	char	*file_path;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		*floor_color_rgb;
	int		*ceiling_color_rgb;
	char	**map;
	char 	**cfg;
	char	**file;
}	t_parsing;

typedef struct s_cub
{
	t_parsing	parsing;
}	t_cub;

/* --- PARSING --- */
int		parsing(t_cub *cub, int argc, char **argv);
int		parsing_file(t_cub *cub);
void	get_cfg(t_cub *cub);
void	get_map(t_cub *cub, int	i);

/* --- MAP PARSING --- */
int		parsing_map(t_cub *cub);
# define POSSIBLE_CHARS "01NSEW \n"

#endif
