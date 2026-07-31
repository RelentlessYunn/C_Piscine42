/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 01:37:31 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 01:37:38 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	print_try(char *prog)
{
	ft_putstr_fd("Try '", 2);
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(" --help' for more information.\n", 2);
}

void	print_usage(char *prog, char *msg, char *arg, int try)
{
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("'\n", 2);
	if (try != 0)
		print_try(prog);
}
