/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:10:15 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/10 15:10:17 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_print_addr(unsigned long n)
{
	char	*hex;
	char	c;
	int		i;

	hex = "0123456789abcdef";
	i = 16;
	while (i > 0)
	{
		i--;
		c = hex[(n >> (i * 4)) & 15];
		write(1, &c, 1);
	}
	write(1, ": ", 2);
}

static void	ft_print_hex(unsigned char *mem, unsigned int size)
{
	unsigned int	i;
	char			*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			write(1, &hex[mem[i] / 16], 1);
			write(1, &hex[mem[i] % 16], 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

static void	ft_print_chars(unsigned char *mem, unsigned int size)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < size)
	{
		c = mem[i];
		if (c < 32 || c > 126)
			c = '.';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*mem;
	unsigned int	i;
	unsigned int	line;

	mem = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		line = size - i;
		if (line > 16)
			line = 16;
		ft_print_addr((unsigned long)addr + i);
		ft_print_hex(mem + i, line);
		ft_print_chars(mem + i, line);
		i = i + 16;
	}
	return (addr);
}

/*
#include <string.h>

int	main(void)
{
	char	*str;

	str = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on "
		"peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	ft_print_memory(str, strlen(str));
	ft_print_memory(str, 0);
	return (0);
}
*/