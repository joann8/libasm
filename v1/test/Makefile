# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 17:52:24 by jacher            #+#    #+#              #
#    Updated: 2021/03/25 16:24:48 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c test_ft_strcpy.c test_ft_strcmp.c test_ft_strlen.c \
		test_ft_strdup.c test_ft_write.c test_ft_read.c test_ft_list.c

OBJS = ${SRCS:.c=.o}

CC = clang

CCFLAGS = -Wall -Werror -Wextra

NAME = test_libasm

${NAME}: ${OBJS} 
	make -C ../libasm
	${CC} ${CCFLAGS} -L ../libasm ${OBJS} -o ${NAME} -lasm

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	make fclean -C ../libasm
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
