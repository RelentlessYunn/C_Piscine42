/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:29:47 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:29:54 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list == NULL)
		return (NULL);
	while (begin_list->next != NULL)
		begin_list = begin_list->next;
	return (begin_list);
}

/*
int	main(void)
{
	t_list	*l;

	l = ft_create_elem("a");
	l->next = ft_create_elem("z");
	printf("%s %p\n", (char *)ft_list_last(l)->data, (void *)ft_list_last(NULL));
	return (0);
}
*/