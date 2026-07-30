/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 10:11:40 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/26 15:15:20 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	put_num(t_ctx *c, int n)
{
	char	buf[16];
	int		len;
	int		i;

	len = 1;
	i = n;
	while (i >= 10)
	{
		i /= 10;
		len++;
	}
	buf[len] = 0;
	i = len;
	while (i > 0)
	{
		buf[i - 1] = '0' + n % 10;
		n /= 10;
		i--;
	}
	return (put_key(c, buf));
}

int	put_group(t_ctx *c, int n)
{
	if (n != 100 && n != 1000 && !put_num(c, n))
		return (0);
	if (n >= 1000)
	{
		if (put_num(c, n / 1000) || put_num(c, 1000))
			return (1);
		n %= 1000;
		if (n && !put_num(c, n))
			return (0);
	}
	if (n >= 100)
	{
		if (put_num(c, n / 100) || put_num(c, 100))
			return (1);
		n %= 100;
		if (n && !put_num(c, n))
			return (0);
	}
	if (n == 0)
		return (0);
	if (put_num(c, n / 10 * 10))
		return (1);
	if (n % 10 == 0)
		return (0);
	return (put_num(c, n % 10));
}

int	put_scale(t_ctx *c, int e)
{
	char	buf[130];
	int		i;

	if (e == 0)
		return (0);
	if (e > 120)
		return (1);
	buf[0] = '1';
	i = 1;
	while (i <= e)
	{
		buf[i] = '0';
		i++;
	}
	buf[i] = 0;
	return (put_key(c, buf));
}

static int	group_value(char *nb, int end, int w)
{
	int	i;
	int	v;

	i = end - w;
	if (i < 0)
		i = 0;
	v = 0;
	while (i < end)
	{
		v = v * 10 + (nb[i] - '0');
		i++;
	}
	return (v);
}

int	solve(char *dict, char *nb, int print, int w)
{
	t_ctx	c;
	int		len;
	int		end;
	int		g;

	c.dict = dict;
	c.print = print;
	c.space = 0;
	len = ft_strlen(nb);
	if (len == 1 && nb[0] == '0')
		return (put_num(&c, 0));
	end = len % w;
	if (end == 0)
		end = w;
	while (end <= len)
	{
		g = group_value(nb, end, w);
		if (g && (put_group(&c, g) || put_scale(&c, len - end)))
			return (1);
		end += w;
	}
	return (0);
}
