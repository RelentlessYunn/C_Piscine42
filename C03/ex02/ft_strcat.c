/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:09:48 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/12 02:09:51 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	a[50] = "Hello, ";
	char	b[50] = "Hello, ";
	char	c[12] = "";
	char	d[12] = "";

	printf("'%s' | '%s'\n", ft_strcat(a, "world!"), strcat(b, "world!"));
	printf("'%s' | '%s'\n", ft_strcat(c, "abc"), strcat(d, "abc"));
	printf("'%s' | '%s'\n", ft_strcat(a, ""), strcat(b, ""));
	return (0);
}
*/