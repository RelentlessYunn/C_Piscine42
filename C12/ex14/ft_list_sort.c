/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:34:24 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:34:29 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_data(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	int		cambiado;

	cambiado = 1;
	while (cambiado == 1)
	{
		cambiado = 0;
		current = *begin_list;
		while (current != NULL && current->next != NULL)
		{
			if ((*cmp)(current->data, current->next->data) > 0)
			{
				swap_data(current, current->next);
				cambiado = 1;
			}
			current = current->next;
		}
	}
}

/*
int	main(void)
{
	t_list	*l;

	l = ft_create_elem("pera");
	l->next = ft_create_elem("kiwi");
	l->next->next = ft_create_elem("42");
	ft_list_sort(&l, &cmp);
	show(l);
	return (0);
}
*/