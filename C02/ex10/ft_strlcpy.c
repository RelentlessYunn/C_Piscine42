/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:09:32 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/10 15:09:33 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/*
#include <stdio.h>

int	main(void)
{
	char	dest[4];

	printf("ret=%u dest=[%s]\n", ft_strlcpy(dest, "abcdef", 2), dest);
	printf("ret=%u dest=[%s]\n", ft_strlcpy(dest, "ab", 4), dest);
	printf("ret=%u (size 0, dest intacta)\n", ft_strlcpy(dest, "xyz", 0));
	return (0);
}
*/
