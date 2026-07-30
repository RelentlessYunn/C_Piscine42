/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 19:57:54 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/09 19:58:03 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>

int	main(void)
{
	int	div;
	int	mod;

	ft_div_mod(17, 5, &div, &mod);
	printf("17 / 5 = %d, 17 %% 5 = %d\n", div, mod);
	return (0);
}
*/
