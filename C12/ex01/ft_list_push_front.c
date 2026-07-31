/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:29:11 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:29:17 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (elem == NULL)
		return ;
	elem->next = *begin_list;
	*begin_list = elem;
}

/*
int	main(void)
{
	t_list	*l;

	l = NULL;
	ft_list_push_front(&l, "c");
	ft_list_push_front(&l, "b");
	ft_list_push_front(&l, "a");
	show(l);
	return (0);
}
*/