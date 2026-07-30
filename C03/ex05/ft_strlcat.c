/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:10:51 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/12 02:10:53 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	i;

	dlen = 0;
	while (dest[dlen] != '\0' && dlen < size)
		dlen++;
	slen = 0;
	while (src[slen] != '\0')
		slen++;
	if (dlen == size)
		return (size + slen);
	i = 0;
	while (src[i] != '\0' && dlen + i < size - 1)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}

/*
#include <stdio.h>

int	main(void)
{
	char	dest[20] = "Hola ";

	printf("ret = %u\n", ft_strlcat(dest, "42", 20));
	printf("dest = [%s]\n", dest);
	return (0);
}
*/