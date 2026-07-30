/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:28:20 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/29 19:49:36 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	result = (int *)malloc(sizeof(int) * length);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	doble(int n)
{
	return (n * 2);
}

int	main(void)
{
	int	tab[3] = {1, 2, 3};
	int	*res;
	int	i;

	res = ft_map(tab, 3, &doble);
	i = 0;
	while (i < 3)
		printf("%d ", res[i++]);
	printf("\n");
	free(res);
	return (0);
}
*/