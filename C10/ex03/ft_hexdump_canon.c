/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_canon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 05:56:14 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 05:56:18 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_offset8(int off)
{
	char	*hex;
	char	out[8];
	int		i;

	hex = "0123456789abcdef";
	i = 7;
	while (i >= 0)
	{
		out[i] = hex[off & 15];
		off = off >> 4;
		i--;
	}
	write(1, out, 8);
}

void	print_hex_byte(unsigned char c)
{
	char	*hex;
	char	out[3];

	hex = "0123456789abcdef";
	out[0] = hex[(c >> 4) & 15];
	out[1] = hex[c & 15];
	out[2] = ' ';
	write(1, out, 3);
}

void	print_ascii(unsigned char *data, int len)
{
	char	c;
	int		i;

	i = 0;
	while (i < len)
	{
		c = '.';
		if (data[i] >= 32 && data[i] <= 126)
			c = data[i];
		write(1, &c, 1);
		i++;
	}
}

void	print_line_canon(unsigned char *data, int off, int len)
{
	int	i;

	print_offset8(off);
	ft_putstr_fd("  ", 1);
	i = 0;
	while (i < 16)
	{
		if (i == 8)
			ft_putstr_fd(" ", 1);
		if (i < len)
			print_hex_byte(data[off + i]);
		else
			ft_putstr_fd("   ", 1);
		i++;
	}
	ft_putstr_fd(" |", 1);
	print_ascii(data + off, len);
	ft_putstr_fd("|\n", 1);
}
