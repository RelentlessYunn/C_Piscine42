/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenchen <shenchen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:04:27 by shenchen          #+#    #+#             */
/*   Updated: 2026/07/31 05:55:12 by shenchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_buf
{
	unsigned char	*data;
	int				len;
	int				cap;
}	t_buf;

unsigned char	*ft_realloc(unsigned char *old, int oldsize, int newsize);
void			append(t_buf *b, unsigned char *chunk, int n);
int				read_fd(t_buf *b, int fd);
void			ft_putstr_fd(char *str, int fd);
void			print_error(char *prog, char *file);
void			print_all_failed(char *prog);
void			print_offset(int off);
void			print_group(int val);
void			print_line(unsigned char *data, int off, int len);
int				same_line(unsigned char *data, int a, int b);
int				is_dup(unsigned char *data, int off, int size);
int				process_line(unsigned char *data, int off, int size, int star);
void			dump(unsigned char *data, int size);
int				open_and_read(t_buf *b, char *prog, char *file);
int				collect(t_buf *b, int argc, char **argv);
int				has_canon(int argc, char **argv);
void			print_offset8(int off);
void			print_hex_byte(unsigned char c);
void			print_ascii(unsigned char *data, int len);
void			print_line_canon(unsigned char *data, int off, int len);
int				process_canon(unsigned char *data, int off, int size, int star);
void			dump_canon(unsigned char *data, int size);

#endif
