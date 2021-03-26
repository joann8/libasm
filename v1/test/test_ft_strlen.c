/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:17:31 by jacher            #+#    #+#             */
/*   Updated: 2021/03/26 15:58:21 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void test_ft_strlen()
{
	printf("\n**** START TEST FT_STRLEN ****\n");
	
	printf("\nInput : |%s|\n", "hello");
	printf("-------------------------\n");
	printf("   Real function : %zu\n", strlen("hello"));
	printf("     My function : %zu\n", ft_strlen("hello"));	
	
	printf("\nInput : |%s|\n", "hello, this string is pretty long for you to see");
	printf("-------------------------\n");
	printf("   Real function : %zu\n", strlen("hello, this string is pretty long for you to see"));
	printf("     My function : %zu\n", ft_strlen("hello, this string is pretty long for you to see"));

	printf("\nInput (chaine vide) : |%s|\n", "");
	printf("-------------------------\n");
	printf("   Real function : %zu\n", strlen(""));
	printf("     My function : %zu\n", ft_strlen(""));	
	
	printf("\n**** END TEST FT_STRLEN ****\n\n");
}
