/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:23:29 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/22 16:05:23 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

#endif