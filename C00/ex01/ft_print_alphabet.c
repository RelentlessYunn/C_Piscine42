/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   ft_print_alphabet.c                                  :+:      :+:    :+: */
/*                                                      +:+ +:+         +:+   */
/*   By: shenchen <shenchen@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 09:42:34 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/09 09:42:34 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}

/*
int	main(void)
{
	ft_print_alphabet();
	write(1, "\n", 1);
	return (0);
}
*/
