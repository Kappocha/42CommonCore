/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:15:45 by iborge-g          #+#    #+#             */
/*   Updated: 2025/08/05 15:19:55 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_header.h"

void	free_map(t_point **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	cleanup_and_exit(t_program *program)
{
	mlx_destroy_image(program->vars.mlx, program->img.img);
	mlx_destroy_window(program->vars.mlx, program->vars.win);
	mlx_destroy_display(program->vars.mlx);
	free(program->vars.mlx);
	free_map(program->map, program->info.rows_num);
	exit(0);
}

int	close_window(int keycode, t_program *program)
{
	if (keycode == 53 || keycode == 65307)
		cleanup_and_exit(program);
	return (0);
}

int	close_window_esc(t_program *program)
{
	cleanup_and_exit(program);
	return (0);
}

void	show_window(t_map info, t_point **map, t_program *program)
{
	program->info = info;
	program->map = map;
	program->vars.mlx = mlx_init();
	program->img.height = 1080;
	program->img.width = 1920;
	if (!program->vars.mlx)
		return ;
	program->vars.win = mlx_new_window(program->vars.mlx,
			program->img.width, program->img.height, "FACTORIA DE FICCION");
	program->img.img = mlx_new_image(program->vars.mlx,
			program->img.width, program->img.height);
	program->img.addr = mlx_get_data_addr(program->img.img,
			&program->img.bits_per_pixel, &program->img.line_length,
			&program->img.endian);
	draw_grid(&program->img, info.rows_num, info.cols_num, map);
	mlx_put_image_to_window(program->vars.mlx,
		program->vars.win, program->img.img, 0, 0);
	mlx_hook(program->vars.win, 17, 0, close_window_esc, program);
	mlx_hook(program->vars.win, 2, 1L << 0, close_window, program);
	mlx_loop(program->vars.mlx);
}
