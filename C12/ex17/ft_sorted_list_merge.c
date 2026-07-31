/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:35:20 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:35:25 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	t_list	**pos;
	t_list	*elem;

	while (begin_list2 != NULL)
	{
		elem = begin_list2;
		begin_list2 = begin_list2->next;
		pos = begin_list1;
		while (*pos != NULL && (*cmp)((*pos)->data, elem->data) <= 0)
			pos = &(*pos)->next;
		elem->next = *pos;
		*pos = elem;
	}
}

/*
int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_create_elem("b");
	a->next = ft_create_elem("d");
	b = ft_create_elem("a");
	b->next = ft_create_elem("c");
	b->next->next = ft_create_elem("e");
	ft_sorted_list_merge(&a, b, &cmp);
	show(a);
	return (0);
}
*/