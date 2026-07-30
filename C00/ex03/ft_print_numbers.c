/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   ft_print_numbers.c                                   :+:      :+:    :+: */
/*                                                      +:+ +:+         +:+   */
/*   By: shenchen <shenchen@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 09:42:34 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/09 09:42:34 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}

/*
int	main(void)
{
	ft_print_numbers();
	write(1, "\n", 1);
	return (0);
}
*/
