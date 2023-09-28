# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 22:03:15 by anrodri2          #+#    #+#              #
#    Updated: 2023/09/28 16:31:51 by anrodri2         ###   ########.fr        #
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
		parsing/parsing_main.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

#### SYSTEM ####
CC = cc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

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