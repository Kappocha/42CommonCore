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

typedef struct s_map {
    int     rows_num;
    int     cols_num;
}           t_map;

typedef struct s_vars {
    void    *mlx;
    void    *win;
}           t_vars;

typedef struct s_program {
    t_vars vars;
    t_data img;
    t_map info;
    t_point **map;
}               t_program;

void    read_file(int fd);
int     count_rows(int fd);
int     count_cols(int fd);
void    parse_map(int fd, t_point ***map, t_map *info);
void    draw_grid(t_data *data, int rows, int cols, t_point **map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    show_window(t_map info, t_point **map, t_program *program);
void    free_map(t_point **map, int rows);

#endif
