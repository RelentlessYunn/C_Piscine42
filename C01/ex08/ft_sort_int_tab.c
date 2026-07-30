/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 19:57:54 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/09 19:58:03 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int	tab[7];
	int	i;

	tab[0] = 42;
	tab[1] = -3;
	tab[2] = 7;
	tab[3] = 0;
	tab[4] = 7;
	tab[5] = 100;
	tab[6] = 1;
	ft_sort_int_tab(tab, 7);
	i = 0;
	while (i < 7)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
