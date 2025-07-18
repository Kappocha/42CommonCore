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
#include <stdio.h>

void show_window(s_map info, t_point **map)
{
   	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FACTORIA DE FICCION");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	draw_grid(&img, info.rows_num, info.cols_num, map);
	mlx_loop(mlx);
	//Falta liberar todo despues, porfavo hazlo
}

int	main(void)
{
	t_point **mapi;
	s_map   info;
    int fd;
    fd = open("./maps/test_maps/10-2.fdf", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return (1);
    }
    //read_file(fd); // Tu función que lee e imprime el archivo línea a línea
    parse_map(fd, &mapi, &info); // DO-RI-ME
	printf("Punto aleatorio del mapa %i \n", mapi[9][9].z);
	//show_window(info, mapi);
	/*for (int i = 0; i < info.rows_num; i++)
    	free(mapi[i]);
	free(mapi);*/
    close(fd);
    return (0);
}
