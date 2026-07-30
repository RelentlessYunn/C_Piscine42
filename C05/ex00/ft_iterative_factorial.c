/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:00:31 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/13 18:11:20 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	r;

	if (nb < 0)
		return (0);
	r = 1;
	while (nb > 1)
	{
		r *= nb;
		nb--;
	}
	return (r);
}

/*
#include <stdio.h>

int	main()
{
	printf("%d", ft_iterative_factorial(5));
	return (0);
}
*/
