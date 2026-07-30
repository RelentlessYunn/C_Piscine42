/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 10:18:12 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/26 15:14:10 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

typedef struct s_line
{
	int	key_start;
	int	key_end;
	int	val_start;
	int	val_end;
}	t_line;

typedef struct s_ctx
{
	char	*dict;
	int		print;
	int		space;
}	t_ctx;

int		ft_strlen(char *s);
void	ft_putstr(char *s);
int		is_space(char c);
char	*read_file(char *path);
int		line_len(char *s);
int		skip_spaces(char *l, int i, int len);
int		key_eq(char *k, int klen, char *key);
int		parse_line(char *l, int len, t_line *p);
int		put_key(t_ctx *c, char *key);
int		put_num(t_ctx *c, int n);
int		put_group(t_ctx *c, int n);
int		put_scale(t_ctx *c, int e);
int		solve(char *dict, char *nb, int print, int w);

#endif
