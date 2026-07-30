/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 23:56:54 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/19 13:58:24 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_base_len(char *base);

int	ft_nbrlen(long nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long nbr, char *base, int base_len)
{
	char	*res;
	int		len;
	long	n;

	len = ft_nbrlen(nbr, base_len);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
		n = -nbr;
	else
		n = nbr;
	while (len > 0)
	{
		len--;
		if (n == 0 && res[len] == '\0')
			res[len] = base[0];
		else
			res[len] = base[n % base_len];
		n /= base_len;
	}
	if (nbr < 0)
		res[0] = '-';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num;
	int		len_to;

	if (ft_base_len(base_from) == 0 || ft_base_len(base_to) == 0)
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	len_to = ft_base_len(base_to);
	return (ft_itoa_base(num, base_to, len_to));
}
