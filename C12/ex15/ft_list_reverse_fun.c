/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 03:34:38 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:34:42 by shenchen         ###   ########.fr       */
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

int	list_len(t_list *begin_list)
{
	int	len;

	len = 0;
	while (begin_list != NULL)
	{
		len++;
		begin_list = begin_list->next;
	}
	return (len);
}

t_list	*elem_at(t_list *begin_list, int nbr)
{
	while (begin_list != NULL && nbr > 0)
	{
		begin_list = begin_list->next;
		nbr--;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int	i;
	int	len;

	len = list_len(begin_list);
	i = 0;
	while (i < len / 2)
	{
		swap_data(elem_at(begin_list, i), elem_at(begin_list, len - 1 - i));
		i++;
	}
}

/*
int	main(void)
{
	t_list	*l;
	t_list	*primero;

	l = ft_create_elem("a");
	l->next = ft_create_elem("b");
	l->next->next = ft_create_elem("c");
	primero = l;
	ft_list_reverse_fun(l);
	show(l);
	printf("mismo primer nodo: %d\n", primero == l);
	return (0);
}
*/