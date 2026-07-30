/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:04:01 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/13 19:23:20 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	r;

	if (power < 0)
		return (0);
	r = 1;
	while (power > 0)
	{
		r *= nb;
		power--;
	}
	return (r);
}

/*
#include <stdio.h>

int     main()
{
        printf("%i", ft_iterative_power(10, 3));
}
*/
