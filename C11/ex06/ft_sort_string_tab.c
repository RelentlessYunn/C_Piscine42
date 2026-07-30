/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:28:11 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/29 20:11:30 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	cambiado;

	cambiado = 1;
	while (cambiado == 1)
	{
		cambiado = 0;
		i = 0;
		while (tab[i] != 0 && tab[i + 1] != 0)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap_str(&tab[i], &tab[i + 1]);
				cambiado = 1;
			}
			i++;
		}
	}
}

/*
#include <stdio.h>

int	main(void)
{
	char	*tab[4] = {"abc", "abb", "abz", 0};
	int		i;

	ft_sort_string_tab(tab);
	i = 0;
	while (tab[i])
		printf("%s ", tab[i++]);
	printf("\n");
	return (0);
}
*/