/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:04:20 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 05:56:32 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	open_and_read(t_buf *b, char *prog, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error(prog, file);
		return (1);
	}
	if (read_fd(b, fd) < 0)
		print_error(prog, file);
	close(fd);
	return (0);
}

int	collect(t_buf *b, int argc, char **argv)
{
	int	i;
	int	files;
	int	failed;

	files = 0;
	failed = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || argv[i][1] == '\0')
		{
			files++;
			failed += open_and_read(b, argv[0], argv[i]);
		}
		i++;
	}
	if (files == 0)
		read_fd(b, 0);
	if (files > 0 && failed == files)
		print_all_failed(argv[0]);
	if (failed > 0)
		return (1);
	return (0);
}

int	has_canon(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] == '-' && argv[i][1] != '\0')
		{
			while (argv[i][j] != '\0')
			{
				if (argv[i][j] == 'C')
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_buf	b;
	int		status;

	b.data = malloc(4096);
	if (b.data == NULL)
		return (1);
	b.len = 0;
	b.cap = 4096;
	status = collect(&b, argc, argv);
	if (has_canon(argc, argv) == 1)
		dump_canon(b.data, b.len);
	else
		dump(b.data, b.len);
	free(b.data);
	return (status);
}
