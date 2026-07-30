/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:10:04 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/12 02:10:19 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (j < nb && src[j] != '\0')
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

	printf("'%s' | '%s'\n", ft_strncat(a, "world!", 3),
		strncat(b, "world!", 3));
	printf("'%s' | '%s'\n", ft_strncat(a, "xyz", 0), 
		strncat(b, "xyz", 0));
	printf("'%s' | '%s'\n", ft_strncat(a, "ab", 50), 
		strncat(b, "ab", 50));
	return (0);
}
*/