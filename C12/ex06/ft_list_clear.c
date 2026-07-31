/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:30:39 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:30:47 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next;

	while (begin_list != NULL)
	{
		next = begin_list->next;
		(*free_fct)(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}

/*
int	main(void)
{
	t_list	*l;

	l = ft_create_elem(strdup("a"));
	l->next = ft_create_elem(strdup("b"));
	ft_list_clear(l, &free);
	printf("liberada\n");
	return (0);
}
*/