/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:28:15 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/29 19:57:46 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

/*
#include <stdio.h>

int	larga(char *s)
{
	return (s[0] && s[1] && s[2] && s[3]);
}

int	main(void)
{
	char	*tab[3] = {"hola", "ab", "mundo"};

	printf("%d\n", ft_count_if(tab, 3, &larga));
	return (0);
}
*/