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

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SERVER_SRC = server.c
CLIENT_SRC = client.c
SERVER_BONUS = server_bonus.c
CLIENT_BONUS = client_bonus.c

SERVER = server
CLIENT = client
SERVER_BONUS_EXE = server_bonus
CLIENT_BONUS_EXE = client_bonus

all: $(SERVER) $(CLIENT)
bonus: $(SERVER_BONUS_EXE) $(CLIENT_BONUS_EXE)

$(SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SRC) -L$(LIBFT_DIR) -lft

$(CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SRC) -L$(LIBFT_DIR) -lft

$(SERVER_BONUS_EXE): $(SERVER_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS_EXE) $(SERVER_BONUS) -L$(LIBFT_DIR) -lft

$(CLIENT_BONUS_EXE): $(CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS_EXE) $(CLIENT_BONUS) -L$(LIBFT_DIR) -lft

clean:
	@echo "Limpiando archivos objeto..."

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS_EXE) $(CLIENT_BONUS_EXE)
	@echo "Ejecutables eliminados."

re: fclean all

.PHONY: all clean fclean re
