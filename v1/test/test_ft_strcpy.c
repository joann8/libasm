/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:17:31 by jacher            #+#    #+#             */
/*   Updated: 2021/03/05 11:45:44 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

void test_ft_strcpy()
{
	int i;
	char dest_real[1000];
	char dest_ft[1000];
	char *str[] = {"Hello World", "", "Je ne crois pas qu'il y ait de bonnes ou de mauvaises situations moi si je devais resumer ma vie aujourd'hui, je dirais que c'est avant tout des rencontres..", NULL};
	i = 0;
	printf("\n**** START TEST FT_STRCPY ****\n\n");
	while (str[i])
	{
		bzero(dest_real, 1000);
		bzero(dest_ft, 1000);
		printf("Input: |%s|\n", str[i]);
		printf("--------------------------------\n");
		printf("Real strcpy: |%s|\n", strcpy(dest_real, str[i]));
		printf("  My strcpy: |%s|\n", ft_strcpy(dest_ft, str[i]));
		printf("==> strcmp(strcpy, ft_strcpy) = %d\n\n", strcmp(strcpy(dest_real, str[i]), ft_strcpy(dest_real, str[i])));
		i++;
	}
	printf("**** END TEST FT_STRCPY ****\n\n");
}
