/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:35:27 by asavchyn          #+#    #+#             */
/*   Updated: 2026/07/18 20:15:14 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_solve(int grid[4][4], int *views, int pos);
void	ft_print_grid(int grid[4][4]);

static void	ft_error(void)
{
	write(2, "Error\n", 6);
}

static int	ft_parse(char *s, int *views)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (*s < '1' || *s > '4')
			return (0);
		views[i] = *s - '0';
		s++;
		if (i < 15 && *s != ' ')
			return (0);
		if (i < 15)
			s++;
		i++;
	}
	if (*s != '\0')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	views[16];
	int	grid[4][4];
	int	i;

	i = 0;
	while (i < 16)
	{
		grid[i / 4][i % 4] = 0;
		i++;
	}
	if (argc != 2 || !ft_parse(argv[1], views))
	{
		ft_error();
		return (1);
	}
	if (!ft_solve(grid, views, 0))
	{
		ft_error();
		return (1);
	}
	ft_print_grid(grid);
	return (0);
}
