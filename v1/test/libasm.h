/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:16:17 by jacher            #+#    #+#             */
/*   Updated: 2021/03/26 15:57:17 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
#include <stdlib.h>
# define BUFFER_SIZE 5000

typedef struct			s_list
{
	void				*data;
	struct s_list		*next;
}						t_list;

// Tests functions
void test_ft_strlen();
void test_ft_strcpy();
void test_ft_strcmp();
void test_ft_write();
void test_ft_read();
void test_ft_strdup();
void test_ft_list_size(int ac, char **av);
void test_ft_list_push_front(int ac, char **av);

// LibAsm functions
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char* src);
int		ft_strcmp(const char *s1, const char* s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);
int		ft_list_size(t_list *begin_list);
int		ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_sort(t_list **begin_list, int(*cmp)());

#endif
