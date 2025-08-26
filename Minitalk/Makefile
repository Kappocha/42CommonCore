# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: your_user <your_email@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 00:00:00 by your_user        #+#    #+#              #
#    Updated: 2025/08/26 00:00:00 by your_user       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos fuente
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Ejecutables
SERVER = server
CLIENT = client

# Targets
all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SRC) -L$(LIBFT_DIR) -lft

$(CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SRC) -L$(LIBFT_DIR) -lft

clean:
	@echo "Limpiando archivos objeto..."

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	@echo "Ejecutables eliminados."

re: fclean all

.PHONY: all clean fclean re