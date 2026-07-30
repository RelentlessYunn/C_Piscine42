/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 19:57:54 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/09 19:58:03 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 17;
	b = 5;
	ft_ultimate_div_mod(&a, &b);
	printf("div = %d, mod = %d\n", a, b);
	return (0);
}
*/
