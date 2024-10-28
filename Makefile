# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 15:28:50 by eahn              #+#    #+#              #
#    Updated: 2024/10/28 18:23:32 by smiranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -g #-I$(INC_DIR) -I$(LIB_DIR) -I$(MLX_DIR)/include/MLX42 -g

# Target name
NAME = cub3D

# Directories
INC_DIR = ./inc/
LIB_DIR = ./libft/
SRC_DIR = ./src/
MLX_DIR = ./MLX42
OBJ_DIR = ./obj/

# For macOS
MLX42FLAGS  := -lglfw -framework Cocoa -framework OpenGL -framework IOKit

# For Ubuntu:
# MLX42FLAGS    := -lglfw -ldl -lGL

# Library
LIB = $(LIB_DIR)libft.a

# MLX library
MLX_LIB = $(MLX_DIR)/build/libmlx42.a -ldl $(MLX42FLAGS) -pthread -lm

# Source files
SRCS = $(addprefix $(SRC_DIR), display.c draw.c free.c graphic_utils.c \
		keys.c main.c parse_color.c parse_direction.c \
		parse_map.c raycasting.c start_game.c utils.c \
		validate_map.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Default rule
all: $(LIB) libmlx $(OBJS) $(NAME)

# MLX library build rule
libmlx:
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build -j4

# Rule to compile source files into object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Linking rule
$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX_LIB) -ldl -lglfw -pthread -lm -o $(NAME)
	@echo "CUB 3D"
	@echo "by eahn & smiranda"

# Library build rule for libft
$(LIB):
	@make -C $(LIB_DIR)

clean:
	@make -C $(LIB_DIR) fclean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re
