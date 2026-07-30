/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:08:57 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/10 15:09:08 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if (x == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		x = (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9');
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "salut, comment tu vas ? 
	42mots quarante-deux; cinquante+et+un";

	printf("%s\n", ft_strcapitalize(s));
	return (0);
}
*/