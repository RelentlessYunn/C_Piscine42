/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 10:20:56 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/26 15:14:25 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>

int	line_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	skip_spaces(char *l, int i, int len)
{
	while (i < len && is_space(l[i]))
		i++;
	return (i);
}

int	key_eq(char *dkey, int dlen, char *want)
{
	while (dlen > 1 && dkey[0] == '0')
	{
		dkey++;
		dlen--;
	}
	while (dlen > 0 && *want && *dkey == *want)
	{
		dkey++;
		want++;
		dlen--;
	}
	return (dlen == 0 && *want == 0);
}

int	parse_line(char *l, int len, t_line *p)
{
	p->key_start = skip_spaces(l, 0, len);
	p->key_end = p->key_start;
	while (p->key_end < len && l[p->key_end] >= '0' && l[p->key_end] <= '9')
		p->key_end++;
	p->val_start = len;
	p->val_end = len;
	if (p->key_start == len)
		return (0);
	if (p->key_end == p->key_start)
		return (1);
	p->val_start = skip_spaces(l, p->key_end, len);
	if (p->val_start == len || l[p->val_start] != ':')
		return (1);
	p->val_start = skip_spaces(l, p->val_start + 1, len);
	while (p->val_end > p->val_start && is_space(l[p->val_end - 1]))
		p->val_end--;
	if (p->val_end == p->val_start)
		return (1);
	return (0);
}

int	put_key(t_ctx *c, char *key)
{
	t_line	p;
	char	*line;
	int		len;
	int		found;

	found = 0;
	line = c->dict;
	while (*line)
	{
		len = line_len(line);
		if (parse_line(line, len, &p))
			return (1);
		if (!found && key_eq(line + p.key_start, p.key_end - p.key_start, key))
		{
			found = 1;
			if (c->print && c->space && (unsigned char)line[p.val_start] < 128)
				ft_putstr(" ");
			if (c->print)
				write(1, line + p.val_start, p.val_end - p.val_start);
			c->space = 1;
		}
		line += len + (line[len] == '\n');
	}
	return (!found);
}
