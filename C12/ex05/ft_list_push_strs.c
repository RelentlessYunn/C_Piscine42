/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:30:24 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:30:30 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*elem;
	int		i;

	list = NULL;
	i = 0;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		if (elem == NULL)
			return (list);
		elem->next = list;
		list = elem;
		i++;
	}
	return (list);
}

/*
int	main(void)
{
	char	*strs[3] = {"a", "b", "c"};

	show(ft_list_push_strs(3, strs));
	return (0);
}
*/