/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 23:57:06 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/19 16:28:25 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_is_sep(str[i], charset) && ft_is_sep(str[i + 1], charset))
			count++;
		i++;
	}
	return (count);
}

char	*ft_putword(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	while (!ft_is_sep(str[i], charset))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (!ft_is_sep(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		pos;

	strs = (char **)malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	pos = 0;
	while (str[i])
	{
		if (!ft_is_sep(str[i], charset))
		{
			strs[pos] = ft_putword(&str[i], charset);
			pos++;
			while (str[i] && !ft_is_sep(str[i], charset))
				i++;
		}
		else
			i++;
	}
	strs[pos] = NULL;
	return (strs);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str = "Hola,,adios,,,m,u,c,h,o,,juan,prueba,";
	char	*charset = "42";
	char	**strs;
	int		i;

	strs = ft_split(str, charset);
	i = 0;
	while (strs[i])
	{
		printf("Palabra %d: [%s]\n", i, strs[i]);
		free(strs[i]);
		i++;
	}
	free(strs);
	
	return (0);
}
*/