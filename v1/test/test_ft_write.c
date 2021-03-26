/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:51:27 by jacher            #+#    #+#             */
/*   Updated: 2021/03/26 15:58:35 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void ft_putnbr(int n)
{
	long nb;
	char digit;
	
	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = -(long)n;
	}
	if (nb > 10)
		ft_putnbr(nb / 10);
	digit = nb % 10 + '0';	
	write(1, &digit, 1);
}

void ft_write_unit(int fd, char *str)
{
	int ret_real;
	int ret_ft;
	int errno_real;
	int errno_ft;
	int len_str;

	len_str = strlen(str);
	errno = 0 ;
	errno_real = 0;
	errno_ft = 0;
	printf("\n\n>>>>>>>TEST<<<<<<<<<\nThis test use fd = %d", fd);
	printf(" and the following str:\n|%s|\n\n", str);
	if (fd == 1)
		printf("*** Real function write:\n");
	ret_real = write(fd, str, len_str);
	if (fd == 1)
		printf("\n==> The return the real function write is %d.\n", ret_real);
	if (ret_real == -1)
	{
		errno_real = errno;
		printf("!!Error!!\n   Real write set errno to %d\n", errno_real);
		printf("   Strerror is: %s.\n", strerror(errno_real));
	}
	errno = 0;
	if (fd == 1)
		printf("\n*** My function write:\n");
	ret_ft = ft_write(fd, str, len_str);
	if (fd == 1)
		printf("\n==> The return my function write is %d.\n", ret_ft);
	if (ret_ft < 0)
	{
		errno_ft = errno;
		printf("!!Error!!\n   My ft_write set errno to %d\n", errno_ft);
		printf("   Strerror is: %s.\n", strerror(errno_ft));
	}
	printf(">>>>>>>END TEST<<<<<<<<<\n");
	
}

void	test_ft_write(void)
{
	char *test_strs[] = {"|short string|", "|Je ne crois pas qu'il y ait de bonnes ou de mauvaises situations moi si je devais resumer ma vie aujourd'hui, je dirais que c'est avant tout des rencontres..|", "", NULL};
	int i = -1;
	int j = -1;
	int fd_test;
	int read_test;
	char buf_test[BUFFER_SIZE];

	printf("\n***** START TEST FT_WRITE *****\n");
	printf("\n____First tests will write on STDOUT____");
	while (test_strs[++i])
		ft_write_unit(1, test_strs[i]);
	printf("\n______________________________________________________\n");
	printf("\n_____The next tests will write on write_test_file_____");
	fd_test = open("./test_files/write_test_file", O_RDWR);
	if (fd_test == -1)
	{
		printf("Error while opening the test_file\n");
		return;
	}
	while (test_strs[++j])
		ft_write_unit(fd_test, test_strs[j]);
	lseek(fd_test, 0, SEEK_SET);
	while ((read_test = read(fd_test, buf_test, BUFFER_SIZE)) != 0)
	{
		if (read_test == -1)
		{
			printf("Error while reading write_test_file\n");
			close(fd_test);
			return;
		}
		write(1, buf_test, read_test);
	}
	close(fd_test);
	printf("\n\n======Above is the read from the file written.\n");
	printf("It should contain the short string twice then the long string twice.");
	printf("\n_______________________________________________________________\n");
	printf("\n____This test will try to write on a bad file descriptor____\n");
	ft_write_unit(-1, test_strs[0]);
	printf("\n______________________________________________________\n");
	printf("\n\n***** END OF TEST FT_WRITE *****\n\n");
}
