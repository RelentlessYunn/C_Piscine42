/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:22:33 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/19 15:35:00 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;
	int	len;

	len = ft_base_len(base);
	if (len == 0)
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	res = 0;
	while (ft_index(str[i], base) >= 0)
	{
		res = res * len + ft_index(str[i], base);
		i++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	char	*res;

	res = ft_convert_base("  ---+-101010", "01", "0123456789ABCDEF");
	printf("Resultado: %s\n", res);
	free(res);

	res = ft_convert_base("42", "0123456789", "0123356789"); // 3 repetido
	if (!res)
		printf("Base invalida detectada\n");
		
	return (0);
}
*/