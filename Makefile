# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 14:39:53 by abouhlel          #+#    #+#              #
#    Updated: 2021/07/17 01:23:06 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minitalk

HEADER_FILE 		= minitalk.h \
						utils.h

HEADER_FILE_BONUS	= minitalk_bonus.h

FOLDER_SRC			= src/
FOLDER_BONUS		= src/bonus/
FOLDER_UTILS		= src/utils/
FOLDER_HEADER		= header/

SRCS_SERVER			= server.c
SRCS_CLIENT			= client.c

SRCS_SERVER_BONUS	= server_bonus.c
SRCS_CLIENT_BONUS	= client_bonus.c

SRCS_UTILS			= ft_atoi.c \
						ft_putchar.c \
						ft_putnbr.c \
						ft_putstr.c

SRC_SERVER			= $(addprefix ${FOLDER_SRC},${SRCS_SERVER})
SRC_CLIENT			= $(addprefix ${FOLDER_SRC},${SRCS_CLIENT})
SRC_SERVER_BONUS	= $(addprefix ${FOLDER_BONUS},${SRCS_SERVER_BONUS})
SRC_CLIENT_BONUS	= $(addprefix ${FOLDER_BONUS},${SRCS_CLIENT_BONUS})
SRC_UTILS			= $(addprefix ${FOLDER_UTILS},${SRCS_UTILS})
HEADERS				= $(addprefix ${FOLDER_HEADER},${HEADER_FILE})
HEADERS_BONUS		= $(addprefix ${FOLDER_HEADER},${HEADER_FILE_BONUS})


OBJS_SERVER			= ${SRC_SERVER:.c=.o}
OBJS_CLIENT			= ${SRC_CLIENT:.c=.o}
OBJS_SERVER_BONUS	= ${SRC_SERVER_BONUS:.c=.o}
OBJS_CLIENT_BONUS	= ${SRC_CLIENT_BONUS:.c=.o}
OBJS_UTILS			= ${SRC_UTILS:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -rf

ifdef MINITALK_BONUS
OBJ_SERVER			= $(OBJS_UTILS) $(OBJS_SERVER_BONUS)
OBJ_CLIENT			= $(OBJS_UTILS) $(OBJS_CLIENT_BONUS)
HEADER				= $(HEADERS) $(HEADERS_BONUS)
else
OBJ_SERVER			= $(OBJS_UTILS) $(OBJS_SERVER)
OBJ_CLIENT			= $(OBJS_UTILS) $(OBJS_CLIENT)
HEADER				= $(HEADERS)
endif

$(NAME):	server client

all:		${NAME}

%.o: %.c	$(HEADERS)
			@$(CC) -c $(CFLAGS) -o $@ $<

re: 		fclean all

clean:
			@printf "Delete object files\n"
			@${RM} $(OBJS_UTILS) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean:		clean
			@printf "Delete binarie\n"
			@${RM} server client

bonus:
			@printf "Compiling bonus\n"
			@$(MAKE) MINITALK_BONUS=1

server:		$(OBJ_SERVER)
			@printf "Compiling server\n"
			@$(CC) $(CFLAGS) $(OBJ_SERVER) -o server
			@printf "Done server\n"

client:		$(OBJ_CLIENT)
			@printf "Compiling client\n"
			@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o client
			@printf "Done client\n"

.PHONY: 	$(NAME) all clean fclean re bonus
