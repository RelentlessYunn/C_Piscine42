/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:53:04 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 01:28:20 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	tail_file(char *prog, char *file, int n, int *printed)
{
	int	fd;
	int	ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error(prog, "cannot open ", file, " for reading");
		return (1);
	}
	if (printed != NULL)
		print_header(file, (*printed)++);
	ret = dump_last(fd, n);
	if (ret != 0)
		print_error(prog, "error reading ", file, "");
	close(fd);
	return (ret);
}

int	tail_all(char **argv, int argc, int n, int start)
{
	int	i;
	int	printed;
	int	status;
	int	*counter;

	printed = 0;
	status = 0;
	counter = NULL;
	if (argc - start > 1)
		counter = &printed;
	i = start;
	while (i < argc)
	{
		if (tail_file(argv[0], argv[i], n, counter) != 0)
			status = 1;
		i++;
	}
	return (status);
}

int	main(int argc, char **argv)
{
	int	n;
	int	start;

	if (argc < 2 || argv[1][0] != '-' || argv[1][1] != 'c')
		return (0);
	start = 3;
	if (argv[1][2] == '\0')
	{
		if (argc < 3)
			return (0);
		n = ft_atoi(argv[2]);
	}
	else
	{
		n = ft_atoi(argv[1] + 2);
		start = 2;
	}
	if (n == 0)
		return (0);
	if (start >= argc)
		return (dump_last(0, n));
	return (tail_all(argv, argc, n, start));
}
