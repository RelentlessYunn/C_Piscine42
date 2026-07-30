/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:09:10 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/12 02:09:13 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d | %d\n", ft_strcmp("abc", "abc"), strcmp("abc", "abc"));
	printf("%d | %d\n", ft_strcmp("abc", "abd"), strcmp("abc", "abd"));
	printf("%d | %d\n", ft_strcmp("abd", "abc"), strcmp("abd", "abc"));
	printf("%d | %d\n", ft_strcmp("", ""), strcmp("", ""));
	return (0);
}
*/