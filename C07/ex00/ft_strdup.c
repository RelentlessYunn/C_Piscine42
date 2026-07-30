/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 23:56:01 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/19 11:55:38 by shenchen         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str = "Prueba de strdup";
	char	*mi_str;
	char	*sys_str;

	mi_str = ft_strdup(str);
	sys_str = strdup(str);
	printf("Mio: %s\nSys: %s\n", mi_str, sys_str);
	free(mi_str);
	free(sys_str);

	char *vacio = ft_strdup("");
	printf("Vacio: [%s]\n", vacio);
	free(vacio);
	return (0);
}
*/