/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:17:31 by jacher            #+#    #+#             */
/*   Updated: 2021/03/05 13:41:36 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	if (ac == 1)
		printf("Specify the function to test as the 2nd arg. Choose among:\n1.ft_strlen\n2.ft_strcpy\n3.ft_strcmp\n4.ft_write\n5.ft_read\n6.ft_strdup\n");
	else if (ac != 2)
		printf("Error: Wrong number of arguments.\n");
	else if (strcmp(av[1], "1") == 0)
		test_ft_strlen();
	else if (strcmp(av[1], "2") == 0)
		test_ft_strcpy();
	else if (strcmp(av[1], "3") == 0)
		test_ft_strcmp();
	else if (strcmp(av[1], "4") == 0)
		test_ft_write();
	else if (strcmp(av[1], "5") == 0)
		test_ft_read();
	else if (strcmp(av[1],"6") == 0)
		test_ft_strdup();
	else
		printf("Error: the 2nd 	argument is wrong. Choose among:\n1.ft_strlen\n2.ft_strcpy\n3.ft_strcmp\n4.ft_write\n5.ft_read\n6.ft_strdup\n");
	return(1);
}
