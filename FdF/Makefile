# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/09 12:16:48 by iborge-g          #+#    #+#              #
#    Updated: 2025/06/09 12:43:06 by iborge-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

SRCDIR = src
OBJDIR = obj
INCLUDES = -Ilibft -Imlx

SRC = main.c functs/maps/get_map.c functs/maps/rows_col.c \
functs/drawing/base_draw.c functs/display/windows_utils.c
OBJ = $(SRC:.c=.o)

LIBMLX = mlx/libmlx.a
LIBFT = libft/libft.a
CFLAGS =
LIBS = $(LIBFT) $(LIBMLX) -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -g $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) $(INCLUDES)

# Crear carpeta de objetos y compilar .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -g $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Crear carpeta obj si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Limpiar objetos
clean:
	rm -rf $(OBJDIR)

# Limpiar todo
fclean: clean
	rm -f $(NAME)

# Recompilar desde cero
re: fclean all

.PHONY: all clean fclean re
