/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:04:44 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 03:21:38 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_offset(int off)
{
	char	*hex;
	char	out[7];
	int		i;

	hex = "0123456789abcdef";
	i = 6;
	while (i >= 0)
	{
		out[i] = hex[off & 15];
		off = off >> 4;
		i--;
	}
	write(1, out, 7);
}

void	print_group(int val)
{
	char	*hex;
	char	out[5];

	hex = "0123456789abcdef";
	out[0] = ' ';
	out[1] = hex[(val >> 12) & 15];
	out[2] = hex[(val >> 8) & 15];
	out[3] = hex[(val >> 4) & 15];
	out[4] = hex[val & 15];
	write(1, out, 5);
}

void	print_line(unsigned char *data, int off, int len)
{
	int	g;
	int	val;

	print_offset(off);
	g = 0;
	while (g < 8)
	{
		if (g * 2 < len)
		{
			val = data[off + g * 2];
			if (g * 2 + 1 < len)
				val = val + (data[off + g * 2 + 1] << 8);
			print_group(val);
		}
		else
			ft_putstr_fd("     ", 1);
		g++;
	}
	ft_putstr_fd("\n", 1);
}

int	same_line(unsigned char *data, int a, int b)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (data[a + i] != data[b + i])
			return (0);
		i++;
	}
	return (1);
}
