/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:34:51 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:34:55 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (elem == NULL)
		return ;
	while (*begin_list != NULL && (*cmp)((*begin_list)->data, data) <= 0)
		begin_list = &(*begin_list)->next;
	elem->next = *begin_list;
	*begin_list = elem;
}

/*
int	main(void)
{
	t_list	*l;

	l = NULL;
	ft_sorted_list_insert(&l, "kiwi", &cmp);
	ft_sorted_list_insert(&l, "42", &cmp);
	ft_sorted_list_insert(&l, "pera", &cmp);
	ft_sorted_list_insert(&l, "kiwi", &cmp);
	show(l);
	return (0);
}
*/