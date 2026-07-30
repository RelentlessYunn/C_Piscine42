/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 18:53:55 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/14 18:53:57 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_solution(int *board)
{
	char	line[11];
	int		col;

	col = 0;
	while (col < 10)
	{
		line[col] = board[col] + '0';
		col++;
	}
	line[10] = '\n';
	write(1, line, 11);
}

static int	is_valid(int *board, int col, int row)
{
	int	c;

	c = 0;
	while (c < col)
	{
		if (board[c] == row)
			return (0);
		if (board[c] - c == row - col)
			return (0);
		if (board[c] + c == row + col)
			return (0);
		c++;
	}
	return (1);
}

static int	solve(int *board, int col)
{
	int	row;
	int	count;

	if (col == 10)
	{
		print_solution(board);
		return (1);
	}
	count = 0;
	row = 0;
	while (row < 10)
	{
		if (is_valid(board, col, row))
		{
			board[col] = row;
			count += solve(board, col + 1);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];

	return (solve(board, 0));
}

/*
int main()
{
    ft_ten_queens_puzzle();
}
*/