/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 10:16:32 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/26 15:50:17 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static char	*join_free(char *a, char *b, int blen)
{
	char	*res;
	int		alen;
	int		i;

	alen = ft_strlen(a);
	res = (char *)malloc(alen + blen + 1);
	if (!res)
	{
		free(a);
		return (0);
	}
	i = -1;
	while (++i < alen)
		res[i] = a[i];
	i = -1;
	while (++i < blen)
		res[alen + i] = b[i];
	res[alen + blen] = 0;
	free(a);
	return (res);
}

char	*read_file(char *path)
{
	char	buf[1024];
	char	*res;
	int		fd;
	int		n;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	res = (char *)malloc(1);
	if (res)
		res[0] = 0;
	n = read(fd, buf, 1024);
	while (n > 0 && res)
	{
		res = join_free(res, buf, n);
		n = read(fd, buf, 1024);
	}
	close(fd);
	if (n < 0 || !res)
	{
		free(res);
		return (0);
	}
	return (res);
}
