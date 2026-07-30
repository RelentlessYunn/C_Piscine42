/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:28:13 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/21 18:54:43 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) ((Value) * (((Value) > 0) - ((Value) < 0)))

#endif

/*
#include "ft_abs.h"
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ABS(-5));       // 5
	printf("%d\n", ABS(0));        // 0
	printf("%d\n", ABS(3 - 10));   // 7
	return (0);
}
*/