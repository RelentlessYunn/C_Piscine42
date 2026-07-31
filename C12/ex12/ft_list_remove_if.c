/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:33:17 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:33:21 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*next;

	while (*begin_list != NULL)
	{
		if ((*cmp)((*begin_list)->data, data_ref) == 0)
		{
			next = (*begin_list)->next;
			(*free_fct)((*begin_list)->data);
			free(*begin_list);
			*begin_list = next;
		}
		else
			begin_list = &(*begin_list)->next;
	}
}

/*
int	main(void)
{
	t_list	*l;

	l = ft_create_elem(strdup("x"));
	l->next = ft_create_elem(strdup("a"));
	l->next->next = ft_create_elem(strdup("x"));
	ft_list_remove_if(&l, "x", &cmp, &free);
	show(l);
	return (0);
}
*/