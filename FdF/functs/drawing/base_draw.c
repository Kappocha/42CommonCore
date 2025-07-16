#include "../../fdf_header.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
		char	*dst;
		printf("Las posiciones enviadas son: %i, %i", x, y);

		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
}

void draw_line(int x0, int y0, int x1, int y1, void *img)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    printf("Toda la informacion\n dx : %i\n dy : %i\n sx : %i\n sy : %i\n err : %i\n", dx, dy, sx, sy, err);

    while (1)
    {
        my_mlx_pixel_put(img, 10, 10, 0xFFFFFF); // Dibuja el pixel actual

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
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            printf("La x y actual es %i %i \n", x, y);
            if (x < rows - 1)
            {
                draw_line(map[y][x].x, map[y][x].y, map[y][x + 1].x, map[y][x + 1].y, data->img);
            }
            if (y < rows - 1)
            {
                draw_line(map[y][x].x, map[y][x].y, map[y + 1][x].x, map[y + 1][x].y, data->img);
            }
        }
    }
}
