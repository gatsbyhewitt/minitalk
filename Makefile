# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 14:03:45 by abestaev          #+#    #+#              #
#    Updated: 2022/02/27 02:52:05 by abestaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ft_minitalk.h

SERVER_NAME = server
CLIENT_NAME = client

SRC_SERVER = src/server.c src/ft_utils.c src/ft_atoi.c
SRC_CLIENT = src/client.c src/ft_utils.c src/ft_atoi.c

OBJ_SERVER = $(SRC_SERVER:%.c=%.o)
OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

build: $(OBJ_CLIENT) $(OBJ_SERVER) $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(OBJ_CLIENT)
	$(CC) -o $(CLIENT_NAME) $(OBJ_CLIENT) $(CFLAGS) -I$(INCLUDES)

$(SERVER_NAME): $(OBJ_SERVER)
	$(CC) -o $(SERVER_NAME) $(OBJ_SERVER) $(CFLAGS) -I$(INCLUDES)

all: $(CLIENT_NAME) $(SERVER_NAME)

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re

