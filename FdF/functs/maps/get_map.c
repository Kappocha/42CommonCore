#include "../../fdf_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void read_file(int fd)
{
    char *line;
    lseek(fd, 0, SEEK_SET); // Asegúrate de empezar desde el principio del archivo

    while ((line = get_next_line(fd)) != NULL) {
        ft_printf("%s", line);
        free(line);
    }
}

void    mem_map(int fd, t_point ***map)
{
    int n_rows;
    int n_cols;
    int i;

    n_rows = count_rows(fd);
    n_cols = count_cols(fd);
    i = 0;
    lseek(fd, 0, SEEK_SET);

    *map = malloc((n_rows + 1) * sizeof(t_point *));
    if (!*map)
        return ;
    while (i < n_rows)
    {
        (*map)[i] = malloc(n_cols * sizeof(t_point));
        if (!(*map)[i]) {
            while (i > 0)
                free((*map)[--i]);
            free(*map);
            return ;
        }
        i++;
    }
    (*map)[i] = NULL;
    ft_printf("Memoria reservada correctamente...\n");
}

void    parse_map(int fd, t_point ***map)
{
    char    *line;
    char    **pline;
    int     x;
    int     y;
    int     col;

    y = 0;
    mem_map(fd, map);
    lseek(fd, 0, SEEK_SET);
    line = get_next_line(fd);
    while (line != NULL)
    {
        pline = ft_split(line, ' ');
        printf("Linea %i: %s\n", y, line);
        if (!pline)
        {
            free(line);
            return ;
        }
        x = 0;
        col = 0;
        // Saltar los dos primeros valores SOLO en la primera línea
        if (y == 0)
            x = 2;
        while (pline[x] != NULL)
        {
            (*map)[y][col].z = ft_atoi(pline[x]);
            printf("Punto %i: %i\n", col, (*map)[y][col].z);
            x++;
            col++;
        }
        free(line);
        x = 0;
        while (pline[x] != NULL)
        {
            free(pline[x]);
            x++;
        }
        free(pline);
        y++;
        line = get_next_line(fd);
    }
    (*map)[y] = NULL; // Null-terminate the last row
    ft_printf("Parseado correctamente... enserio? \n");
}
