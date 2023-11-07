# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 22:03:15 by anrodri2          #+#    #+#              #
#    Updated: 2023/10/30 18:39:41 by anrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### FINAL COMPILATION FILE ###
NAME = cub3D

#### DIRECTORIES ####
SRC_DIR = src/

OBJS_DIR = .objs/

INC_DIR = inc/

LIB_DIR = libs/libft

#### SOURCE FILES ####
LIBFT = $(LIB_DIR)/libft.a


MLX = mlx_linux/libmlx.a

SRCS =	main.c \
		custom_exit.c \
		parsing/parsing_main.c \
		parsing/parsing_file.c \
		parsing/fill_struct.c \
		parsing/cfg_parsing/check_cfg.c \
		parsing/cfg_parsing/parse_cfg.c \
		parsing/map/parsing_map_main.c \
		parsing/map/parsing_map_loop.c \
		mlx/mlx_main.c \
		mlx/mlx_hooks.c \
		display/print_map.c \
		display/player.c \
		display/ray_casting/init_ray_cast.c \
		display/ray_casting/ray_casting_main.c \
		display/ray_casting/tools.c \
		display/ray_casting/move_player.c\
		display/ray_casting/drawing_walls.c
		display/print_mapbg.c \
		display/shapes/print_rect.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

#### SYSTEM ####
CC = cc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g3

DFLAGS = -MMD -MP

LFLAGS = -L $(LIB_DIR) -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz

IFLAGS = -I $(INC_DIR) -I $(LIB_DIR) -Imlx_linux -O3

#### RULES ####
all:		$(NAME)

-include	$(DEPS)

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
			$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) $(MLX) $(LIBFT) -o $@

$(LIBFT):	FORCE
			$(MAKE) all -j -C $(LIB_DIR)

$(MLX):
			$(MAKE) all -j -C mlx_linux/

FORCE:
$(OBJS_DIR)%.o:		$(SRC_DIR)%.c
					mkdir -p $(shell dirname $@)
					$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

clean:
			$(MAKE) clean -C $(LIB_DIR)
			$(RM) $(OBJS_DIR) $(DEPS)

fclean:		clean
			$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re FORCE