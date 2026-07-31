/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:05:00 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 05:55:33 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

unsigned char	*ft_realloc(unsigned char *old, int oldsize, int newsize)
{
	unsigned char	*new;
	int				i;

	new = malloc(newsize);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < oldsize)
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

void	append(t_buf *b, unsigned char *chunk, int n)
{
	int	i;

	while (b->data != NULL && b->len + n > b->cap)
	{
		b->data = ft_realloc(b->data, b->len, b->cap * 2);
		b->cap = b->cap * 2;
	}
	if (b->data == NULL)
		return ;
	i = 0;
	while (i < n)
	{
		b->data[b->len + i] = chunk[i];
		i++;
	}
	b->len = b->len + n;
}

int	read_fd(t_buf *b, int fd)
{
	unsigned char	tmp[4096];
	int				ret;

	ret = read(fd, tmp, 4096);
	while (ret > 0)
	{
		append(b, tmp, ret);
		ret = read(fd, tmp, 4096);
	}
	return (ret);
}
