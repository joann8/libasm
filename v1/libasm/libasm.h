/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:16:17 by jacher            #+#    #+#             */
/*   Updated: 2021/03/25 19:24:08 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>

typedef struct			s_list
{
	void				*data;
	struct s_list		*next;
}						t_list;



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
