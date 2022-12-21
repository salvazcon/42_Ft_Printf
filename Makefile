# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 18:39:43 by saazcon-          #+#    #+#              #
#    Updated: 2022/11/15 19:23:31 by saazcon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c ft_put.c
OBJS	= ${SRCS:.c=.o}
SRCSLIB	= libft/ft_strlen.c
OBJSLIB = ${SRCSLIB:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar rc
ARF		= ranlib

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJSLIB} ${OBJS}
			${AR} ${NAME} ${OBJSLIB} ${OBJS}
			${ARF} ${NAME}

clean:
			${RM} ${OBJSLIB} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re