# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 17:52:24 by jacher            #+#    #+#              #
#    Updated: 2021/03/25 18:39:28 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlen.s \
ft_strcpy.s \
ft_strcmp.s \
ft_write.s \
ft_read.s \
ft_strdup.s

SRCS_BONUS = ft_list_size_bonus.s \
ft_list_push_front_bonus.s \
ft_list_sort_bonus.s

OBJS = ${SRCS:.s=.o}

OBJS_BONUS = ${SRCS_BONUS:.s=.o}

AS = nasm

ASFLAGS = -felf64

NAME = libasm.a

${NAME}: ${OBJS} libasm.h
	ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all

bonus: ${OBJS_BONUS} ${OBJS} libasm.h
	ar -rcs ${NAME} ${OBJS} ${OBJS_BONUS}

.PHONY: all clean fclean re
