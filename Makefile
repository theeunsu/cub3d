# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 15:28:50 by eahn              #+#    #+#              #
#    Updated: 2024/10/09 12:14:01 by eahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Target name
NAME = cub3d

# Directories
INC_DIR = ./inc/
LIB_DIR = ./libft/
SRC_DIR = ./src/
MLX_DIR = ./MLX42/
MLX_URL = https://github.com/codam-coding-college/MLX42.git
OBJ_DIR	 = ./obj/

# Library
LIB = $(LIB_DIR)libft.a

# Source files
SRCS = $(addprefix $(SRC_DIR), main.c utils.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Compilation rules
libmlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
			git clone $(MLX_URL) $(MLX_DIR); \
	fi
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build --parallel 4

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR) -c $< -o $@

# Linking rule
$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "CUB 3D"
	@echo "by eahn & smiranda"

# Library build rule
$(LIB):
	@make -C $(LIB_DIR)

# General rules
all: libmlx $(NAME)

clean:
	@make -C $(LIB_DIR) fclean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re
