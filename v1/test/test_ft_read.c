/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:51:27 by jacher            #+#    #+#             */
/*   Updated: 2021/03/05 13:36:50 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

void test_ft_read(void)
{
	int fd_real;
	int fd_ft;
	char *test_files[] = {"./test_files/empty_file", 
		"notfound_file", "/bin/", "./test_files/other_file", NULL};
	int i = -1;
	int ret_real;
	int ret_ft;
	char buf_real[BUFFER_SIZE + 1];
	char buf_ft[BUFFER_SIZE + 1];
	int errno_real;
	int errno_ft;

	printf("**** START TEST FT_READ ****\n");
	printf("\nThe BUFFER_SIZE is %d.\n", BUFFER_SIZE);
	while (test_files[++i])
	{
		printf("\n>>>>>>TEST<<<<<<\n");
		printf("The file tested is |%s|\n", test_files[i]);
		fd_real = open(test_files[i], O_RDONLY);
		fd_ft = open(test_files[i], O_RDONLY);
		ret_real = -1;
		ret_ft = -1;
		errno_real = 0;
		errno_ft = 0;
		bzero(buf_real, BUFFER_SIZE + 1);
		bzero(buf_ft, BUFFER_SIZE + 1);
		if (strcmp(test_files[i], "notfound_file") != 0
			&& (fd_real == -1 || fd_ft == -1))
		{
			printf("%s\n", strerror(errno));
			if (fd_real != -1)
				close(fd_real);
			if (fd_ft != -1)
				close(fd_ft);
			return ;
		}
		while ((ret_real = read(fd_real, buf_real, BUFFER_SIZE)) != -2) 
		{
			printf(">> Real read returned %d\n", ret_real);
			if (ret_real != -1)
				printf("The buffer was filled with:\n|%s|\n", buf_real);
			if (ret_real == -1)
			{
				errno_real = errno;
				printf("Errno for the real read is %d\n", errno_real);
				printf("Strerror for the real read returns |%s|\n", strerror(errno_real));
			}
			else
				buf_real[ret_real] = '\0';
			errno = 0;	
			ret_ft = ft_read(fd_ft, buf_ft, BUFFER_SIZE);
			printf(">> My ft_read returned %d\n", ret_ft);
			if (ret_ft != -1)	
				printf("The buffer was filled with:\n|%s|\n", buf_ft);
			if (ret_ft < 0)
			{
				errno_ft = errno;
				printf("Errno for my ft_read is %d\n", errno_ft);
				printf("Strerror for my ft_read returns |%s|\n", strerror(errno_ft));
			}
			else
				buf_ft[ret_ft] = '\0';
			if (ret_real == -1)
			{
				break ;
			}
		if (ret_real == 0 && ret_ft == 0)
				break ;
		}
		close(fd_real);
		close(fd_ft);
		printf(">>>>>>END TEST<<<<<<\n");
	}
	ret_ft = 0;
	bzero(buf_ft, BUFFER_SIZE + 1);
	printf("\n\nThe next part is to test ft_read with STDIN\n");
	printf("\nPress Ctrl+D when you're done\n");
	while ((ret_ft = ft_read(1, buf_ft, BUFFER_SIZE)) != 0)
	{
		if (ret_ft < BUFFER_SIZE)
			buf_ft[ret_ft - 1] = '\0'; //to trim \n
		else
			buf_ft[ret_ft] = '\0';
		if (ret_ft == -1)
		{
			printf("Error while readind STDIN\n");
			printf("Errno was set to %d\n", errno);
			printf("%s\n", strerror(errno));
			break ;
		}
		printf("Ft_read returns : %d\n", ret_ft);
		printf("And the buffer was filled with |%s|\n", buf_ft);
	}
	printf("**** END TEST FT_READ ****\n");
	return;
}
