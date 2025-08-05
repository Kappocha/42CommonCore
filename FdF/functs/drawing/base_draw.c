#include "../../fdf_header.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
		char	*dst;

		if (x >= data->width || y >= data->height || x < 0 || y < 0 )
		    return ;

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

void draw_map_line(t_point p1, t_point p2, int espaciado, int offset_x, int offset_y, t_data *data)
{
    int xp1, yp1, xp2, yp2;
    project_iso(p1.x * espaciado, p1.y * espaciado, p1.z, &xp1, &yp1);
    project_iso(p2.x * espaciado, p2.y * espaciado, p2.z, &xp2, &yp2);
    draw_line(
        xp1 + offset_x, yp1 + offset_y,
        xp2 + offset_x, yp2 + offset_y,
        data
    );
}

void draw_grid(t_data *data, int rows, int cols, t_point **map)
{
    int y;
    int x;
    int offset_x = 0;
    int offset_y = 0;
    int espaciado;

    printf("%i %i \n", data->width, data->height);
    printf("%i %i \n", rows, cols);
    espaciado = (data->width / (cols + rows)) / 2;
    if (espaciado < 2)
        espaciado = 2;
    offset_x = (data->width - cols * espaciado);
    offset_y = (data->height - rows * espaciado);
    if (rows <= 201 || cols <= 201)
    {
        offset_x /= 2;
        offset_y /= 2;
    }
    printf("%i", espaciado);

    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            // Dibuja línea a la derecha
            if (x < cols - 1) {
                draw_map_line(
                    map[y][x], map[y][x + 1],
                    espaciado, offset_x, offset_y, data
                );
            }
            // Dibuja línea abajo
            if (y < rows - 1) {
                draw_map_line(
                    map[y][x], map[y + 1][x],
                    espaciado, offset_x, offset_y, data
                );
            }
        }
    }
}
