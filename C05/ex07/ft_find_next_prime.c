/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 18:47:36 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/14 18:47:37 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (2);
	while (i * i <= nb)
	{
		if ((nb % i) == 0)
			return (ft_find_next_prime(nb + 1));
		i++;
	}
	return (nb);
}

/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_find_next_prime(9));
	printf("%d\n", ft_find_next_prime(1312317));
}
*/