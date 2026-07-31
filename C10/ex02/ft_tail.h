/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:53:14 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 01:36:53 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(char *str);
void	print_error(char *prog, char *action, char *file, char *tail);
void	print_last(char *data, int size, int n);
void	print_header(char *file, int printed);
char	*ft_realloc(char *old, int oldsize, int newsize);
char	*read_all(int fd, int *size);
int		dump_last(int fd, int n);
int		tail_file(char *prog, char *file, int n, int *printed);
int		tail_all(char **argv, int argc, int n, int start);
int		is_number(char *str);
void	print_try(char *prog);
void	print_usage(char *prog, char *msg, char *arg, int try);
int		parse_args(int argc, char **argv, int *n);

#endif
