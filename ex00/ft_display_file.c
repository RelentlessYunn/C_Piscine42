/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:00:22 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/28 19:07:53 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

int	display_content(int fd)
{
	char	buf[4096];
	int		ret;

	ret = read(fd, buf, 4096);
	while (ret > 0)
	{
		write(1, buf, ret);
		ret = read(fd, buf, 4096);
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Too many arguments.\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		return (0);
	}
	if (display_content(fd) < 0)
		ft_putstr_fd("Cannot read file.\n", 2);
	close(fd);
	return (0);
}
