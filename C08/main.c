/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:56:17 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/22 16:05:15 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					i;

	tab = ft_strs_to_tab(ac, av);
	i = 0;
	while (tab[i].str != 0)
	{
		printf("[%d] size=%d str='%s' copy='%s'\n",
			i, tab[i].size, tab[i].str, tab[i].copy);
		i++;
	}
	printf("terminador str==NULL -> %d\n", tab[i].str == 0);
	i = 0;
	while (i < ac)
		free(tab[i++].copy);
	free(tab);
	return (0);
}
