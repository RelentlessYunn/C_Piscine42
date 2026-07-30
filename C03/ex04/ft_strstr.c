/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:10:35 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/12 02:10:37 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("'%s' | '%s'\n", ft_strstr("hello world", "world"),
		strstr("hello world", "world"));
	printf("'%s' | '%s'\n", ft_strstr("mississippi", "ss"),
		strstr("mississippi", "ss"));
	printf("'%s' | '%s'\n", ft_strstr("abcabcabd", "cab"),
		strstr("abcabcabd", "cab"));
	printf("'%s' | '%s'\n", ft_strstr("abc", ""), strstr("abc", ""));
	return (0);
}
*/