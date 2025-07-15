/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:59:49 by iborge-g          #+#    #+#             */
/*   Updated: 2025/06/19 19:17:00 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
		char	*dst;

		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
}

void	draw_square(t_data img)
{
	int	x0 = 20;
	int	y0 = 20;
	int offset = 100;

	int	x = offset;
	while (x <= x0 + offset)
		my_mlx_pixel_put(&img, x++, offset, 0x00FFFFFF);
	x = offset;
	while (x <= x0 + offset)
		my_mlx_pixel_put(&img, x++, offset + y0, 0x00FFFFFF);
	int	y = offset;
	while (y <= y0 + offset)
		my_mlx_pixel_put(&img, offset, y++, 0x00FFFFFF);
	y = offset;
	while (y <= y0 + offset)
		my_mlx_pixel_put(&img, offset + x0, y++, 0x00FFFFFF);

}

void show_window()
{
   	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x = 5;
	int		y = 5;
	int		cx = 0;
	int		cy = 0;
	int		size = 20;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FACTORIA DE FICCION");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_square(img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int	main(void)
{
	t_point **mapi;
    int fd = open("10-2.fdf", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return (1);
    }
    int n_rows = count_rows(fd);
    read_file(fd); // Tu función que lee e imprime el archivo línea a línea
    parse_map(fd, &mapi); // DO-RI-ME
	printf("Punto aleatorio del mapa %i", mapi[9][9].z);
	for (int i = 0; i < n_rows; i++)
    	free(mapi[i]);
	free(mapi);
    close(fd);
    return (0);
}
