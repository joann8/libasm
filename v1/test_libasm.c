/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libasm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:17:31 by jacher            #+#    #+#             */
/*   Updated: 2021/03/04 16:00:28 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm/libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
	
	printf("\n**** END TEST FT_STRLEN ****\n");
}

void test_ft_strcpy()
{
	char d1[10];
	char d2[10];
	char d3[10];
	char d4[10];
	char d5[10];
	char d6[10];
	char d7[0];
	char d8[0];
	char *s;
	char *s2;
	
	s = "hello";
	s2 = "hola que tal la vida?";
	
	printf("\n**** START TEST FT_STRCPY ****\n");
	
	printf("\nDest: |%s| | size = %lu\n", d1, strlen(d1));
	printf("Source: |%s| | size = %lu\n", s, strlen(s));
	printf("-------------------------\n");
	printf("   Real function - dest: |%s|\n", strcpy(d1, s));
	printf("     My function - dest: |%s|\n", ft_strcpy(d2, s));	
		
	printf("\nDest: |%s| | size = %lu\n", d3, strlen(d3));
	printf("Source: |%s| | size = %lu\n", s2, strlen(s2));
	printf("-------------------------\n");
	printf("   Real function - dest: |%s|\n", strcpy(d3, s2));
	printf("     My function - dest: |%s|\n", ft_strcpy(d4, s2));	
	
	printf("\nDest: |%s| | size = %lu\n", d5, strlen(d5));
	printf("Source: |%s| | size = %lu\n", "", strlen(""));
	printf("-------------------------\n");
	printf("   Real function - dest: |%s|\n", strcpy(d5, ""));
	printf("     My function - dest: |%s|\n", ft_strcpy(d6, ""));	
	
	printf("\nDest: |%s| | size = %lu\n", d7, strlen(d7));
	printf("Source: |%s| | size = %lu\n", s, strlen(s));
	printf("-------------------------\n");
	printf("   Real function - dest: |%s|\n", strcpy(d7, s));
	printf("     My function - dest: |%s|\n", ft_strcpy(d8, s));	
	
	printf("\n**** END TEST FT_STRCPY ****\n");
}

void test_ft_strcmp()
{
	
	printf("\n**** START TEST FT_STRCMP ****\n");
	
	printf("\ns1: |%s|\n", "hello");
	printf("s2: |%s|\n", "hello you");
	printf("-------------------------\n");
	printf("   Real function : %d\n", strcmp("hello", "hello you"));
	printf("     My function : %d\n", ft_strcmp("hello", "hello you"));	
	
	printf("\ns1: |%s|\n", "hello you");
	printf("s2: |%s|\n", "hello");
	printf("-------------------------\n");
	printf("   Real function : %d\n", strcmp("hello you", "hello"));
	printf("     My function : %d\n", ft_strcmp("hello you", "hello"));	
	
	printf("\ns1: |%s|\n", "How are you?");
	printf("s2: |%s|\n", "How are you?");
	printf("-------------------------\n");
	printf("   Real function : %d\n", strcmp("How are you?", "How are you?"));
	printf("     My function : %d\n", ft_strcmp("How are you?", "How are you?"));	
	
	printf("\ns1: |%s|\n", "How dare you?");
	printf("s2: |%s|\n", "How are you?");
	printf("-------------------------\n");
	printf("   Real function : %d\n", strcmp("How dare you?", "How are you?"));
	printf("     My function : %d\n", ft_strcmp("How dare you?", "How are you?"));	
	
	printf("\ns1: |%s|\n", "How are you?");
	printf("s2: |%s|\n", "How dare you?");
	printf("-------------------------\n");
	printf("   Real function : %d\n", strcmp("How are you?", "How dare you?"));
	printf("     My function : %d\n", ft_strcmp("How are you?", "How dare you?"));	
	
	printf("\ns1: |%s|\n", "ok?");
	printf("s2: |%s|\n", "");
	printf("-------------------------\n");
	printf("   Real function : %d\n", strcmp("ok?", ""));
	printf("     My function : %d\n", ft_strcmp("ok?", ""));	
	
	printf("\ns1: |%s|\n", "");
	printf("s2: |%s|\n", "");
	printf("-------------------------\n");
	printf("   Real function : %d\n", strcmp("", ""));
	printf("     My function : %d\n", ft_strcmp("", ""));	

	printf("\ns1: |%s|\n", "");
	printf("s2: |%s|\n", "ok?");
	printf("-------------------------\n");
	printf("   Real function : %d\n", strcmp("", "ok?"));
	printf("     My function : %d\n", ft_strcmp("", "ok?"));	
	
	printf("\n**** END TEST FT_STRCMP ****\n");
}


int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	test_ft_strlen();
	//test_ft_strcpy();
	//test_ft_strcmp();
	return(1);
}
