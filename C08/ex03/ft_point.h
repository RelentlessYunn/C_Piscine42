/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:28:29 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/21 18:57:42 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif

/*
#include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point	point;

	set_point(&point);
	return (0);
}
*/