/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:09:32 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/12 02:09:34 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d | %d\n", ft_strncmp("abc", "abd", 0), strncmp("abc", "abd", 0));
	printf("%d | %d\n", ft_strncmp("abc", "abd", 2), strncmp("abc", "abd", 2));
	printf("%d | %d\n", ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
	printf("%d | %d\n", ft_strncmp("abc", "abc", 100),
	strncmp("abc", "abc", 100));
	printf("%d | %d\n", ft_strncmp("", "", 5), strncmp("", "", 5));
	return (0);
}
*/