/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:07:59 by iborge-g          #+#    #+#             */
/*   Updated: 2025/06/09 12:53:58 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_point {
    int         x;
    int         y;
    int         z;
    unsigned int    color;
}           t_point;

void    read_file(int fd);
int     count_rows(int fd);
int     count_cols(int fd);
void    parse_map(int fd, t_point ***map);
void    draw_grid(t_data *data, int rows, int cols, t_point **map);

#endif
