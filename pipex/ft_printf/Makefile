# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 12:30:14 by ckarl             #+#    #+#              #
#    Updated: 2023/01/04 12:30:50 by ckarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c ft_printbasics.c ft_printptr.c ft_printhex.c ft_itoa_u.c \
			ft_itoa.c ft_printnbr.c

OBJS		= ${SRCS:.c=.o}

HEADER		= ft_printf.h

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I${HEADER}

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
