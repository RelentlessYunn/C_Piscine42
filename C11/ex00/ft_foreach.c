/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:28:22 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/29 18:48:40 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*
#include <stdio.h>

void	show(int n)
{
	printf("%d ", n);
}

int	main(void)
{
	int	tab[3] = {1, 2, 3};

	ft_foreach(tab, 3, &show);
	printf("\n");
	return (0);
}
*/
