/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libasm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:17:31 by jacher            #+#    #+#             */
/*   Updated: 2021/03/05 12:02:57 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LIBASM_H
# define TEST_LIBASM_H

# include "../libasm/libasm.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# define BUFFER_SIZE 5000


void test_ft_strlen();
void test_ft_strcpy();
void test_ft_strcmp();
void test_ft_write();
void test_ft_read();
void test_ft_strdup();

#endif
