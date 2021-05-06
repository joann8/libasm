/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:17:31 by jacher            #+#    #+#             */
/*   Updated: 2021/03/26 16:38:28 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"


t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return ;
	new->next = *alst;
	*alst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	print_list(t_list *l)
{
	t_list	*tmp;
	int 	i;

	tmp = l;
	i = 1;
	while (tmp)
	{
		printf("%d.%s\n", i, (char*)tmp->data);
		tmp = tmp->next;
		i++;
	}
	printf("\n");
}

void test_ft_list_size(int ac, char **av)
{
	printf("\n**** START TEST FT_LIST_SIZE ****\n");
	printf("\nThe test list are the the command line arguments:\n");
	
	t_list	*l;
	int 	i;

	l = NULL;
	i = 0;
	while (i < ac)
	{
		ft_lstadd_front(&l, ft_lstnew((void *)av[i]));
		i++;
	}
	printf("   List_size = %d\n", ft_lstsize(l));
	printf("ft_list_size = %d\n", ft_list_size(l));
	
	printf("\nThe test with NULL pointer:\n");
	printf("   List_size = %d\n", ft_lstsize(NULL));
	printf("ft_list_size = %d\n", ft_list_size(NULL));
	printf("\n**** END TEST FT_LIST_SIZE ****\n\n");
}

void test_ft_list_push_front(int ac, char **av)
{
	printf("\n**** START TEST FT_ADD_FRONT ****\n");
	printf("\nThe test list are the the command line arguments.\n");
	
	t_list	*l;
	t_list	*l2;
	int 	i;
	char 	*str;
	char 	*str2;

	l = NULL;
	i = 0;
	while (i < ac)
	{
		ft_lstadd_front(&l, ft_lstnew((void *)av[i]));
		i++;
	}
	str = "hello";
	printf("\nRegular list add front: add str |%s|\n", str);
	ft_lstadd_front(&l, ft_lstnew((void *)str));
	print_list(l);
	printf("My list push front: add str |%s|\n", str);
	ft_list_push_front(&l, ft_lstnew((void *)str));
	print_list(l);

	str2 = NULL;
	printf("\nRegular list add front: add str |%s|\n", str2);
	ft_lstadd_front(&l, ft_lstnew((void *)str2));
	print_list(l);
	printf("My list push front: add str |%s|\n", str2);
	ft_list_push_front(&l, ft_lstnew((void *)str2));
	print_list(l);

	printf("\nRegular list add front: NULL list + add str |%s|\n", str);
	ft_lstadd_front(NULL, ft_lstnew((void *)str));
	printf("My list push front: NULL list + add str |%s|\n", str);
	ft_list_push_front(NULL, ft_lstnew((void *)str));
	
	printf("\n**** END TEST FT_ADD_FRONT ****\n\n");
}
