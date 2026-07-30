/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 23:56:15 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/19 11:55:29 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (!arr)
		return (NULL);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}

/*
#include <stdio.h>

int	main(void)
{
	int	*r;
	int	i;
	int	min = -5;
	int	max = 5;

	r = ft_range(min, max);
	if (r)
	{
		i = 0;
		while (i < (max - min))
		{
			printf("%d ", r[i]);
			i++;
		}
		printf("\n");
		free(r);
	}
	int *nulo = ft_range(5, 5);
	if (!nulo)
		printf("Devuelve NULL correctamente.\n");
	return (0);
}
*/