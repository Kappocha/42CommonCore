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

int	main(void)
{
    t_program program;
    int fd;

    // Inicializa punteros a NULL por seguridad
    program.map = NULL;
    program.vars.mlx = NULL;
    program.vars.win = NULL;
    program.img.img = NULL;

    fd = open("./maps/test_maps/10-2.fdf", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return (1);
    }
    parse_map(fd, &program.map, &program.info);
    show_window(program.info, program.map, &program);
    close(fd);
    return (0);
}
