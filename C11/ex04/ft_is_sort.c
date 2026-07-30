/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:28:13 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/30 18:10:57 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascendente;
	int	descendente;

	i = 0;
	ascendente = 1;
	descendente = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			ascendente = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			descendente = 0;
		i++;
	}
	if (ascendente == 1 || descendente == 1)
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	cmp(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int	ok[3] = {1, 2, 3};
	int	ko[3] = {1, 3, 2};

	printf("%d %d\n", ft_is_sort(ok, 3, &cmp), ft_is_sort(ko, 3, &cmp));
	return (0);
}
*/

// int	ft_is_sort(int *tab, int length, int (*f)(int, int))
// {
// 	int	i;

// 	i = 0;
// 	while (i < length - 1)
// 	{
// 		if (f(tab[i], tab[i + 1]) > 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }