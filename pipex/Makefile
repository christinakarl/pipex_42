# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 17:38:19 by ckarl             #+#    #+#              #
#    Updated: 2023/06/19 17:20:41 by ckarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c ft_split.c ft_putstr_fd.c

OBJS			= ${SRCS:.c=.o}

HEADER  		= pipex.h

NAME			= pipex

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror -g

RM				= rm -f

COLOUR_GREEN	=\033[1;32m
COLOUR_RED		=\033[0;31m
COLOUR_YELL		=\033[0;33m
COLOUR_TURQ		=\033[1;36m
COLOUR_WHITE	=\033[1;37m
COLOUR_BLUE		=\033[1;34m
COLOUR_VIO		=\033[1;35m
COLOUR_END		=\033[0m

%.o: %.c
				${CC} -c ${CFLAGS} $< -o $@

all:			${NAME}

${NAME}:		${OBJS}
				cd ft_printf; make
				${CC} ${CFLAGS} -o $@ ${OBJS} -Lft_printf -lftprintf -Ift_printf
				@echo "$(COLOUR_GREEN)( ಠ ͜ʖ ಠ )$(COLOUR_END)"

clean:
				${RM} ${OBJS}
				cd ft_printf; make clean

fclean:			clean
				${RM} ${NAME}
				cd ft_printf; make fclean
				@echo "$(COLOUR_VIO)All clean!$(COLOUR_END)"

re:				fclean all

.PHONY:			all clean fclean re

