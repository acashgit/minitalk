# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acash <acash@student.21-school.r>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:28:45 by acash             #+#    #+#              #
#    Updated: 2021/11/16 16:28:46 by acash            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVERB = server_bonus
CLIENTB = client_bonus

GCC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCSSER = server.c \

SRCSCLI = client.c \

UTILS = minitalk_utils.c \

SRCSSERB = server_bonus.c \

SRCSCLIB = client_bonus.c \

UTILSB = minitalk_utils_bonus.c \

OBJSS = $(SRCSSER:.c=.o)
OBJSC = $(SRCSCLI:.c=.o)
OBJSU = $(UTILS:.c=.o)

OBJSSB = $(SRCSSERB:.c=.o)
OBJSCB = $(SRCSCLIB:.c=.o)
OBJSUB = $(UTILSB:.c=.o)

all:  $(SERVER) $(CLIENT)

$(SERVER): $(OBJSS) $(OBJSU) minitalk.h Makefile
	@$(GCC) $(CFLAGS) $(OBJSS) $(OBJSU) -o $(SERVER)

$(CLIENT): $(OBJSC) $(OBJSU) minitalk.h Makefile
	@$(GCC) $(CFLAGS) $(OBJSC) $(OBJSU) -o $(CLIENT)

$(SERVERB): $(OBJSSB) $(OBJSUB) minitalk_bonus.h Makefile
	@$(GCC) $(CFLAGS) $(OBJSSB) $(OBJSUB) -o $(SERVERB)

$(CLIENTB): $(OBJSCB) $(OBJSUB) minitalk_bonus.h Makefile
	@$(GCC) $(CFLAGSB) $(OBJSCB) $(OBJSUB) -o $(CLIENTB)	

bonus: $(SERVERB) $(CLIENTB)

clean:
	rm -f $(OBJSS) $(OBJSC) $(OBJSU) $(OBJSSB) $(OBJSCB) $(OBJSUB)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVERB) $(CLIENTB) $(OBJSS) $(OBJSC) $(OBJSU) $(OBJSSB) $(OBJSCBmake) $(OBJSUB) 

re: fclean all

.PHONY: all clean fclean re bonus