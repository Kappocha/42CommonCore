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

NAME = push_swap

CC = gcc
INCLUDES = -Ilibft

SRC = main.c include/listas/lists1.c include/listas/lists2.c \
include/listas/lists3.c include/node/node_functs.c \
include/turk/movement.c include/aux/aux.c include/turk/stack_move.c \
include/aux/push_swap_utils.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
CFLAGS = -g -fsanitize=address
LIBS = $(LIBFT)
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) $(INCLUDES)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Limpiar objetos
clean:
	rm -f $(OBJ)

# Limpiar todo
fclean: clean
	rm -f $(NAME)

# Recompilar desde cero
re: fclean all
.PHONY: all clean fclean re
