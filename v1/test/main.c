/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:17:31 by jacher            #+#    #+#             */
/*   Updated: 2021/03/25 18:45:15 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	if (ac == 1)
		printf("Specify the function to test as the 2nd arg. Choose among:***REGULAR***\n1.ft_strlen\n2.ft_strcpy\n3.ft_strcmp\n4.ft_write\n5.ft_read\n6.ft_strdup\n***BONUS***7.ft_list_size\n8.ft_list_push_front\n9.ft_list_sort\n");
	else if (ac == 2)
	{
		if (strcmp(av[1], "1") == 0)
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
			printf("Error: Wrong arguments. Choose among:\n***REGULAR***\n1.ft_strlen\n2.ft_strcpy\n3.ft_strcmp\n4.ft_write\n5.ft_read\n6.ft_strdup\n***BONUS***7.ft_list_size\n8.ft_list_push_front\n9.ft_list_sort\n");
	}
	if (ac >= 2 && strcmp(av[1], "7") == 0)
		test_ft_list_size(ac, av);
	else if (ac >= 2 && strcmp(av[1], "8") == 0)
		test_ft_list_push_front(ac, av);
	else if (ac >= 2 && strcmp(av[1], "9") == 0)
		test_ft_list_sort(ac, av);
	else
		printf("Error: Wrong arguments. Choose among:\n***REGULAR***\n1.ft_strlen\n2.ft_strcpy\n3.ft_strcmp\n4.ft_write\n5.ft_read\n6.ft_strdup\n***BONUS***7.ft_list_size\n8.ft_list_push_front\n9.ft_list_sort\n");
	return(1);
}
