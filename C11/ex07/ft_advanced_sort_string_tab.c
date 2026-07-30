/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:28:09 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/29 20:12:32 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[i], tab[i + 1]) > 0)
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
#include <string.h>

int	al_reves(char *a, char *b)
{
	return (strcmp(b, a));
}

int	main(void)
{
	char	*tab[4] = {"abc", "abb", "abz", 0};
	int		i;

	ft_advanced_sort_string_tab(tab, &al_reves);
	i = 0;
	while (tab[i])
		printf("%s ", tab[i++]);
	printf("\n");
	return (0);
}
*/