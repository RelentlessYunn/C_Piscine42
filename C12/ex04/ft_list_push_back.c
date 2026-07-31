/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:30:04 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:30:15 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*last;

	elem = ft_create_elem(data);
	if (elem == NULL)
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = elem;
		return ;
	}
	last = *begin_list;
	while (last->next != NULL)
		last = last->next;
	last->next = elem;
}

/*
int	main(void)
{
	t_list	*l;

	l = NULL;
	ft_list_push_back(&l, "a");
	ft_list_push_back(&l, "b");
	ft_list_push_back(&l, "c");
	show(l);
	return (0);
}
*/