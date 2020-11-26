# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/11 14:27:14 by hheimerd          #+#    #+#              #
#    Updated: 2020/09/23 17:12:15 by hheimerd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS 		= -Wall -Wextra -Werror -fpic -O2 
CC 			= clang
NAME 		= cub3D
HEADER		= headers/cub3d.h headers/libft.h 
LIB_DIR		= libft
LIB			= $(LIB_DIR)/libft.a
HEADER_OBJ	= $(HEADER:.h=.h.gch)
HEADER_SO	= $(HEADER:.h=.so)
SRC			= main/main.c \
				GNL/get_next_line.c GNL/get_next_line_utils.c \
				main/color_utils/cast_color.c main/color_utils/shaders.c \
				main/output_utils/image_helper.c main/output_utils/draw_elem.c\
				main/output_utils/error.c main/output_utils/do_snap.c\
				main/hook_parse/hooks_parse.c \
				main/map_module/map.c\
				main/math_things/range.c\
				main/parser/parser.c main/parser/map_checker.c
SRC_OBJ		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(SRC_OBJ) $(LIB) $(HEADER_OBJ)
	 $(CC) $(LIB) -include headers $(SRC_OBJ) -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIB):
	make -C $(LIB_DIR);
	make clean -C $(LIB_DIR)

clean:
	rm -f $(SRC_OBJ) $(HEADER_OBJ)

fclean: clean
	rm -f $(NAME) $(HEADER_SO)
	make fclean -C $(LIB_DIR)

re: fclean all

$(HEADER_OBJ):$(HEADER)
	$(CC) $(FLAGS) -c $(HEADER) $<

.c.o:
	$(CC) $(FLAGS) -c $< -o $@
