/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:53:36 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 01:39:00 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	write(fd, str, i);
}

int	ft_atoi(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}

void	print_error(char *prog, char *action, char *file, char *tail)
{
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(action, 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(tail, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	print_last(char *data, int size, int n)
{
	int	start;

	if (data == NULL)
		return ;
	start = 0;
	if (size > n)
		start = size - n;
	write(1, data + start, size - start);
}

void	print_header(char *file, int printed)
{
	if (printed > 0)
		ft_putstr_fd("\n", 1);
	ft_putstr_fd("==> ", 1);
	ft_putstr_fd(file, 1);
	ft_putstr_fd(" <==\n", 1);
}
