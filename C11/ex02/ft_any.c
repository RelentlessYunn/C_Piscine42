/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:28:18 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/29 19:52:22 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	vacia(char *s)
{
	return (s[0] == '\0');
}

int	main(void)
{
	char	*tab[4] = {"hola", "", "mundo", 0};

	printf("%d\n", ft_any(tab, &vacia));
	return (0);
}
*/