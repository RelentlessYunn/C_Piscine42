/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:29:29 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 06:21:39 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list != NULL)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

/*
int	main(void)
{
	t_list	*l;

	l = ft_create_elem("a");
	l->next = ft_create_elem("b");
	printf("%d %d\n", ft_list_size(l), ft_list_size(NULL));
	return (0);
}
*/