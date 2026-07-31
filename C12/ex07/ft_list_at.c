/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:31:12 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:31:16 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list != NULL)
	{
		if (i == nbr)
			return (begin_list);
		i++;
		begin_list = begin_list->next;
	}
	return (NULL);
}

/*
int	main(void)
{
	t_list	*l;

	l = ft_create_elem("a");
	l->next = ft_create_elem("b");
	printf("%s %s %p\n", (char *)ft_list_at(l, 0)->data,
		(char *)ft_list_at(l, 1)->data, (void *)ft_list_at(l, 9));
	return (0);
}
*/