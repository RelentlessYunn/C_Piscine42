/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:53:28 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 01:37:15 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char	*ft_realloc(char *old, int oldsize, int newsize)
{
	char	*new;
	int		i;

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

char	*read_all(int fd, int *size)
{
	char	*data;
	int		len;
	int		cap;
	int		ret;

	cap = 4096;
	len = 0;
	data = malloc(cap);
	ret = -1;
	while (data != NULL)
	{
		ret = read(fd, data + len, cap - len);
		if (ret <= 0)
			break ;
		len += ret;
		if (len == cap)
		{
			data = ft_realloc(data, len, cap * 2);
			cap = cap * 2;
		}
	}
	*size = len;
	if (ret < 0)
		*size = -1;
	return (data);
}

int	dump_last(int fd, int n)
{
	char	*data;
	int		size;

	size = 0;
	data = read_all(fd, &size);
	if (size >= 0)
		print_last(data, size, n);
	free(data);
	if (size < 0)
		return (1);
	return (0);
}
