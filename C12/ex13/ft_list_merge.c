/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:33:31 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:33:35 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*last;

	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	last = *begin_list1;
	while (last->next != NULL)
		last = last->next;
	last->next = begin_list2;
}

/*
int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_create_elem("a");
	b = ft_create_elem("b");
	b->next = ft_create_elem("c");
	ft_list_merge(&a, b);
	show(a);
	return (0);
}
*/