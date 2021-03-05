/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:17:31 by jacher            #+#    #+#             */
/*   Updated: 2021/03/05 11:33:54 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

static void	return_value(int ret)
{
	if (ret == 0)
		printf(" return value is 0.\n");
	if (ret < 0)
		printf(" return value is negative\n");
	if (ret > 0)
		printf(" return value is positive\n");
}

void		test_ft_strcmp()
{
	char *str[]= { "hello", "hello you", "hello you", "hello", "How are you?", "How are you?", "How dare you?", "How are you?",  "How are you?", "How dare you?", "ok", "", "", "ok", "","", NULL };
	int i;

	printf("\n**** START TEST FT_STRCMP ****\n");
	i = 0;
	while (str[i])
	{
		printf("\ns1: |%s|\n", str[i]);
		printf("s2: |%s|\n", str[i + 1]);
		printf("-------------------------\n");
		printf("   Real function :");
		return_value(strcmp(str[i], str[i + 1]));
		printf("     My function :");
		return_value(ft_strcmp(str[i], str[i + 1]));
		i += 2;
	}
	printf("\n**** END TEST FT_STRCMP ****\n\n");
}
