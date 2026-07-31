/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:31:43 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:31:47 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

/*
void	print_it(void *d)
{
	printf("[%s]", (char *)d);
}

int	main(void)
{
	t_list	*l;

	l = ft_create_elem("a");
	l->next = ft_create_elem("b");
	ft_list_foreach(l, &print_it);
	printf("\n");
	return (0);
}
*/