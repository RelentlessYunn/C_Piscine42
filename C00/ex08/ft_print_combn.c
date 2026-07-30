/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      :::::::: */
/*   ft_print_combn.c                                     :+:      :+:    :+: */
/*                                                      +:+ +:+         +:+   */
/*   By: shenchen <shenchen@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 09:42:34 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/09 09:42:34 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	char	num[10];
	int		i;

	i = 0;
	while (i < n)
	{
		num[i] = i + '0';
		i++;
	}
	while (1)
	{
		write(1, num, n);
		if (num[0] == (10 - n) + '0')
			break ;
		write(1, ", ", 2);
		i = n - 1;
		while (num[i] == (10 - n + i) + '0')
			i--;
		num[i]++;
		while (i < n - 1)
		{
			num[i + 1] = num[i] + 1;
			i++;
		}
	}
}

/*
int	main(void)
{
	int     a;
    a = 1;
	while(a <= 9)
    {
        ft_print_combn(a);
        write(1, "\n", 1);
        a++;
    }
	return (0);
}
*/
