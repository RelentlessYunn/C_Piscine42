/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 23:56:27 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/19 12:05:51 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (size);
}

/*
#include <stdio.h>

int	main(void)
{
	int	*range;
	int	size;
	int	i;

	size = ft_ultimate_range(&range, -5, 5);
	printf("Size: %d\n", size);
	i = 0;
	while (i < size)
	{
		printf("%d ", range[i]);
		i++;
	}
	printf("\n");
	if (range)
		free(range);

	size = ft_ultimate_range(&range, 10, 10);
	printf("Size: %d\n", size);
	return (0);
}
*/