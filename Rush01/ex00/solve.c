/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:45:32 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/18 23:49:56 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_visible(int *line);
static int	ft_check_row(int grid[4][4], int *views, int row);
static int	ft_check_col(int grid[4][4], int *views, int col);
static int	ft_can_place(int grid[4][4], int row, int col, int val);
int			ft_solve(int grid[4][4], int *views, int pos);

static int	ft_visible(int *line)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_check_row(int grid[4][4], int *views, int row)
{
	int	line[4];
	int	rev[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][i];
		rev[i] = grid[row][3 - i];
		i++;
	}
	if (ft_visible(line) != views[8 + row])
		return (0);
	if (ft_visible(rev) != views[12 + row])
		return (0);
	return (1);
}

static int	ft_check_col(int grid[4][4], int *views, int col)
{
	int	line[4];
	int	rev[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i][col];
		rev[i] = grid[3 - i][col];
		i++;
	}
	if (ft_visible(line) != views[col])
		return (0);
	if (ft_visible(rev) != views[4 + col])
		return (0);
	return (1);
}

static int	ft_can_place(int grid[4][4], int row, int col, int val)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == val || grid[i][col] == val)
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve(int grid[4][4], int *views, int pos)
{
	int	row;
	int	col;
	int	val;

	if (pos == 16)
		return (1);
	row = pos / 4;
	col = pos % 4;
	val = 1;
	while (val <= 4)
	{
		if (ft_can_place(grid, row, col, val))
		{
			grid[row][col] = val;
			if ((col != 3 || ft_check_row(grid, views, row))
				&& (row != 3 || ft_check_col(grid, views, col))
				&& ft_solve(grid, views, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		val++;
	}
	return (0);
}
