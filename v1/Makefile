# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 17:52:24 by jacher            #+#    #+#              #
#    Updated: 2021/03/04 16:03:54 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = test_libasm.c

OBJS = ${SRCS:.c=.o}

CC = clang

CCFLAGS = -Wall -Werror -Wextra

NAME = test_libasm

${NAME}: ${OBJS} 
	make -C libasm
	${CC} ${CCFLAGS} -L./libasm ${OBJS} -o ${NAME} -lasm

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	make fclean -C libasm
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
