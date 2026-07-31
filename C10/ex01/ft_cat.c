/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:48:36 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/30 23:20:50 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	write(fd, str, i);
}

void	print_error(char *prog, char *file)
{
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

int	cat_fd(int fd)
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

int	cat_file(char *prog, char *file)
{
	int	fd;
	int	err;

	fd = 0;
	if (!(file[0] == '-' && file[1] == '\0'))
		fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error(prog, file);
		return (1);
	}
	err = 0;
	if (cat_fd(fd) < 0)
	{
		print_error(prog, file);
		err = 1;
	}
	if (fd != 0)
		close(fd);
	return (err);
}

int	main(int argc, char **argv)
{
	int	i;
	int	status;

	status = 0;
	if (argc == 1)
		status = (cat_fd(0) < 0);
	i = 1;
	while (i < argc)
	{
		if (cat_file(argv[0], argv[i]))
			status = 1;
		i++;
	}
	return (status);
}
