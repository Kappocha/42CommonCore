#include "../../fdf_header.h"
#include <stdio.h>
#define ESPACIADO 40

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
		char	*dst;

		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
}

void draw_line(int x0, int y0, int x1, int y1, t_data *data)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        my_mlx_pixel_put(data, x0, y0, 0xFFFFFF);
        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_grid(t_data *data, int rows, int cols, t_point **map)
{
    int y;
    int x;

    y = 0;
    while (y < rows)
    {
        x = 0;
        while (x < cols) {
            if (x < cols - 1) {
                draw_line(map[y][x].x * ESPACIADO, map[y][x].y * ESPACIADO,
                    map[y][x + 1].x * ESPACIADO, map[y][x + 1].y * ESPACIADO, data);
            }
            if (y < rows - 1) {
                draw_line(map[y][x].x * ESPACIADO, map[y][x].y * ESPACIADO,
                    map[y + 1][x].x * ESPACIADO, map[y + 1][x].y * ESPACIADO, data);
            }
            x++;
        }
        y++;
    }
}
