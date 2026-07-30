/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:52:13 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/29 18:52:14 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	get_op_index(char *op)
{
	char	*operators;
	int		i;

	operators = "+-*/%";
	i = 0;
	while (operators[i] != '\0')
	{
		if (op[0] == operators[i] && op[1] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

void	fill_functions(int (**functions)(int, int))
{
	functions[0] = &ft_add;
	functions[1] = &ft_sub;
	functions[2] = &ft_mul;
	functions[3] = &ft_div;
	functions[4] = &ft_mod;
}

int	main(int argc, char **argv)
{
	int	(*functions[5])(int, int);
	int	index;
	int	value2;

	if (argc != 4)
		return (0);
	index = get_op_index(argv[2]);
	if (index == -1)
	{
		ft_putstr("0\n");
		return (0);
	}
	fill_functions(functions);
	value2 = ft_atoi(argv[3]);
	if (index == 3 && value2 == 0)
		ft_putstr("Stop : division by zero\n");
	else if (index == 4 && value2 == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
	{
		ft_putnbr(functions[index](ft_atoi(argv[1]), value2));
		ft_putstr("\n");
	}
	return (0);
}
