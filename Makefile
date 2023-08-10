# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 16:31:55 by donglee2          #+#    #+#              #
#    Updated: 2023/08/10 14:47:16 by donglee2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BONUS_NAME = fdf_bonus
CC = cc
CFLAGS = -fsanitize=address -g
# CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L./00libft -lft
MLXFLAG = -lmlx -framework OpenGL -framework AppKit

MANDATORY_DIRS = ./mandatory_files

MANDATORY_SRCS = $(MANDATORY_DIRS)/arguments_check.c\
$(MANDATORY_DIRS)/coordinate_coordinates.c\
$(MANDATORY_DIRS)/iso_projection.c\
$(MANDATORY_DIRS)/main_helper.c\
$(MANDATORY_DIRS)/main.c\
$(MANDATORY_DIRS)/make_t_point_arr_helper.c\
$(MANDATORY_DIRS)/make_t_point_arr.c\
$(MANDATORY_DIRS)/mesure_size.c\
$(MANDATORY_DIRS)/mlx.c\
$(MANDATORY_DIRS)/put_dots_dda_helper.c\
$(MANDATORY_DIRS)/put_dots_dda.c\
$(MANDATORY_DIRS)/put_dots.c\

BONUS_DIRS = ./bonus_files

BONUS_SRCS = $(BONUS_DIRS)/arguments_check_bonus.c\
$(BONUS_DIRS)/coordinate_coordinates_bonus.c\
$(BONUS_DIRS)/iso_projection_bonus.c\
$(BONUS_DIRS)/key_handler_2_bonus.c\
$(BONUS_DIRS)/key_handler_1_bonus.c\
$(BONUS_DIRS)/key_handler_bonus.c\
$(BONUS_DIRS)/main_helper_bonus.c\
$(BONUS_DIRS)/main_bonus.c\
$(BONUS_DIRS)/make_t_point_arr_helper_bonus.c\
$(BONUS_DIRS)/make_t_point_arr_bonus.c\
$(BONUS_DIRS)/mesure_size_bonus.c\
$(BONUS_DIRS)/mlx_bonus.c\
$(BONUS_DIRS)/put_dots_dda_helper_bonus.c\
$(BONUS_DIRS)/put_dots_dda_bonus.c\
$(BONUS_DIRS)/put_dots_bonus.c\

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -rf

MAKE = make

LIBFT = 00libft/libft.a
MLX = mlx/libmlx.dylib

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./00libft bonus

$(MLX):
	$(MAKE) -C ./mlx

$(NAME): $(MANDATORY_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJS) $(LDFLAGS) $(MLXFLAG)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LDFLAGS) $(MLXFLAG)
	touch $@

clean:	
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS) bonus
	$(MAKE) -C ./00libft clean
	$(MAKE) -C ./mlx clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(RM) $(LIBFT) $(MLX)
	
re: fclean all
