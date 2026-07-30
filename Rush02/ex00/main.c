/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 10:12:05 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/26 17:44:13 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>
#include <unistd.h>

static int	dict_width(char *dict)
{
	t_ctx	c;

	c.dict = dict;
	c.print = 0;
	c.space = 0;
	if (put_key(&c, "10000") || put_key(&c, "100000000"))
		return (3);
	return (4);
}

static int	is_valid_nb(char *s)
{
	int	i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i > 0 && s[i] == 0);
}

static int	run(char *path, char *nb)
{
	char	*dict;
	int		ret;
	int		w;

	dict = read_file(path);
	if (!dict)
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	while (nb[0] == '0' && nb[1])
		nb++;
	w = dict_width(dict);
	ret = solve(dict, nb, 0, w);
	if (ret)
		write(2, "Dict Error\n", 11);
	else
	{
		solve(dict, nb, 1, w);
		ft_putstr("\n");
	}
	free(dict);
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && is_valid_nb(argv[1]))
		return (run("numbers.dict", argv[1]));
	if (argc == 3 && is_valid_nb(argv[2]))
		return (run(argv[1], argv[2]));
	if (argc == 2 || argc == 3)
		write(2, "Error\n", 6);
	if (argc != 2 && argc != 3)
		write(2, "Invalid number of arguments\n", 28);
	return (1);
}
