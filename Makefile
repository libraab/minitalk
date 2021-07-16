# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 14:39:53 by abouhlel          #+#    #+#              #
#    Updated: 2021/07/16 23:22:07 by abouhlel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CF = utils.c

C = client.c

S = server.c

CB = client_bonus.c

SB = server_bonus.c

CFOBJ = $(CF:.c=.o)

COBJ = $(C:.c=.o)

SOBJ = $(S:.c=.o)

SBOBJ = $(SB:.c=.o)

CBOBJ = $(CB:.c=.o)

CFLAGS = -Wall -Wextra -Werror

ifdef MINITALK_BONUS
OBJ_SERVER 				= $(CFOBJ) $(SBOBJ)
OBJ_CLIENT 				= $(CFOBJ) $(CBOBJ)
HEADER 					= minitalk.h minitlak_bonus.h
else
OBJ_SERVER 				= $(CFOBJ) $(SOBJ)
OBJ_CLIENT 				= $(CFOBJ) $(COBJ)
HEADER 					= minitalk.h
endif

$(NAME) : client server

%.o: %.c	$(HEADER)
			gcc -c $(CFLAGS) -o $@ $<

all: $(NAME)

client: $(OBJ_CLIENT)
			gcc $(CFLAGS) $(OBJ_CLIENT) -o client

server: $(OBJ_SERVER)
			gcc $(CFLAGS) $(OBJ_SERVER) -o server
bonus:
		$(MAKE) MINITALK_BONUS=1
		
clean:
		rm -rf $(CFOBJ) $(SOBJ) $(SBOBJ) $(CBOBJ) $(COBJ)

fclean: clean
		rm -rf client server

re: fclean all

.PHONY: bonus $(NAME) clean fclean re all