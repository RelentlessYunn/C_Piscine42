/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   ft_is_negative.c                                     :+:      :+:    :+: */
/*                                                      +:+ +:+         +:+   */
/*   By: shenchen <shenchen@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 09:42:34 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/09 09:42:34 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}

/*
int	main(void)
{
	ft_is_negative(-42);
	ft_is_negative(0);
	ft_is_negative(42);
	ft_is_negative(-2147483648);
	ft_is_negative(2147483647);
	write(1, "\n", 1);
	return (0);
}
*/
