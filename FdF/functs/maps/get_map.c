#include "../../fdf_header.h"
#include <stdio.h>
#include <stdlib.h>

void read_file(int fd)
{
    char *line;
    lseek(fd, 0, SEEK_SET); // Asegúrate de empezar desde el principio del archivo

    while ((line = get_next_line(fd)) != NULL) {
        free(line);
    }
}

void    mem_map(int fd, t_point ***map, s_map *info)
{
    int i;
    int n_cols;
    int n_rows;

    n_cols = count_cols(fd);
    n_rows = count_rows(fd);
    (*info).cols_num = n_cols;
    (*info).rows_num = n_rows;
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
}

void    parse_map(int fd, t_point ***map, s_map *info)
{
    char    *line;
    char    **pline;
    int     x;
    int     y;

    y = 0;
    mem_map(fd, map, info);
    lseek(fd, 0, SEEK_SET);
    printf("Ei Ei Mun!");
    line = get_next_line(fd);
    while (line != NULL)
    {
        pline = ft_split(line, ' ');
        if (!pline)
        {
            free(line);
            return ;
        }
        x = 0;
        while (pline[x] != NULL)
        {
            (*map)[y][x].x = x;
            (*map)[y][x].y = y;
            (*map)[y][x].z = ft_atoi(pline[x]);
            free(pline[x]);
            x++;
        }
        free(pline);
        free(line);
        y++;
        line = get_next_line(fd);
    }
    (*map)[y] = NULL; // Null-terminate the last row
}
