# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 17:52:24 by jacher            #+#    #+#              #
#    Updated: 2021/03/26 16:28:25 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = test_ft_strcpy.c \
test_ft_strcmp.c \
test_ft_strlen.c \
test_ft_strdup.c \
test_ft_write.c \
test_ft_read.c

OBJS = ${SRCS:.c=.o}

SRCS_BONUS = main_bonus.c test_ft_list.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = clang

CCFLAGS = -Wall -Werror -Wextra

NAME = test_libasm

${NAME}: ${OBJS} main.o libasm.h  
	make -C ../libasm
	${CC} ${CCFLAGS} -L ../libasm ${OBJS} main.o -o ${NAME} -lasm 

all: ${NAME}

clean:
	rm -f ${OBJS} ${OBJS_BONUS} main.o

fclean: clean
	make fclean -C ../libasm
	rm -f ${NAME}

re: fclean all

bonus:: ${OBJS} ${OBJS_BONUS} libasm.h  
	make bonus -C ../libasm
	${CC} ${CCFLAGS} -L ../libasm ${OBJS} ${OBJS_BONUS} -o ${NAME} -lasm 



.PHONY: all clean fclean re
