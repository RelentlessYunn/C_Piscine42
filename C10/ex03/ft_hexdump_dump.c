/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_dump.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:04:34 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 05:55:57 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	is_dup(unsigned char *data, int off, int size)
{
	if (off < 16)
		return (0);
	if (size - off < 16)
		return (0);
	return (same_line(data, off, off - 16));
}

int	process_line(unsigned char *data, int off, int size, int star)
{
	int	linelen;

	linelen = 16;
	if (size - off < 16)
		linelen = size - off;
	if (is_dup(data, off, size))
	{
		if (!star)
			ft_putstr_fd("*\n", 1);
		return (1);
	}
	print_line(data, off, linelen);
	return (0);
}

void	dump(unsigned char *data, int size)
{
	int	off;
	int	star;

	if (size <= 0)
		return ;
	off = 0;
	star = 0;
	while (off < size)
	{
		star = process_line(data, off, size, star);
		off += 16;
	}
	print_offset(size);
	ft_putstr_fd("\n", 1);
}

int	process_canon(unsigned char *data, int off, int size, int star)
{
	int	linelen;

	linelen = 16;
	if (size - off < 16)
		linelen = size - off;
	if (is_dup(data, off, size))
	{
		if (star == 0)
			ft_putstr_fd("*\n", 1);
		return (1);
	}
	print_line_canon(data, off, linelen);
	return (0);
}

void	dump_canon(unsigned char *data, int size)
{
	int	off;
	int	star;

	if (size <= 0)
		return ;
	off = 0;
	star = 0;
	while (off < size)
	{
		star = process_canon(data, off, size, star);
		off += 16;
	}
	print_offset8(size);
	ft_putstr_fd("\n", 1);
}
