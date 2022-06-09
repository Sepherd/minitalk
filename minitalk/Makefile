# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arecce <arecce@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 11:39:40 by arecce            #+#    #+#              #
#    Updated: 2022/06/09 15:46:24 by arecce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

APP1 = server
APP2 = client
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBRARY = ft_printf/libftprintf.a

CLIENT =	client.c

SERVER =	server.c

OBJS_CLIENT = $(CLIENT:.c=.o)

OBJS_SERVER = $(SERVER:.c=.o)

all: lib server client

server: $(OBJS_SERVER)
	$(CC) $(CFLAGS) $^ -o $(APP1) $(LIBRARY)

client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $^ -o $(APP2) $(LIBRARY)

lib:
	make -C ./ft_printf

norme:  all
	norminette server.c client.c minitalk.h ./ft_printf

deb: lib
	$(CC) $(CFLAGS) $(SERVER) -o $(APP1) -g $(LIBRARY)
	$(CC) $(CFLAGS) $(CLIENT) -o $(APP2) -g $(LIBRARY)

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	make clean -C ./ft_printf

fclean: clean
	$(RM) $(APP1) $(APP2)
	make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re server client deb lib