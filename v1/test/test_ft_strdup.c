/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:17:31 by jacher            #+#    #+#             */
/*   Updated: 2021/03/26 15:58:13 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void test_ft_strdup()
{
	int i;
	char *str[] = {"Hello World", "", "Je ne crois pas qu'il y ait de bonnes ou de mauvaises situations moi si je devais resumer ma vie aujourd'hui, je dirais que c'est avant tout des rencontres..", NULL};
	i = 0;
	printf("\n**** START TEST FT_STRCPY ****\n\n");
	while (str[i])
	{
		printf("Input: |%s|\n", str[i]);
		printf("--------------------------------\n");
		printf("Real strdup: |%s|\n", strdup(str[i]));
		printf("  My strdup: |%s|\n", ft_strdup(str[i]));
		printf("==> strcmp(strdup, ft_strdup) = %d\n\n", strcmp(strdup(str[i]), ft_strdup(str[i])));
		i++;
	}
	printf("**** END TEST FT_STRCPY ****\n\n");
}
