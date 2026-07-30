/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 23:56:39 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/19 12:39:38 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	if (size == 0)
		return (0);
	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += ft_strlen(sep) * (size - 1);
	return (total);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;

	if (size == 0)
	{
		res = (char *)malloc(sizeof(char));
		if (res)
			res[0] = '\0';
		return (res);
	}
	res = (char *)malloc(sizeof(char) * (ft_total_len(size, strs, sep) + 1));
	if (!res)
		return (NULL);
	res[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i < size - 1)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*strs[] = {"Hola", "Mundo", "desde", "42"};
	char	*sep = " // ";
	char	*res;

	res = ft_strjoin(3, strs, sep);
	printf("Resultado: %s\n", res);
	free(res);
	
	res = ft_strjoin(0, strs, sep);
	printf("Size 0: [%s]\n", res);
	free(res);
	
	return (0);
}
*/