#include "../../fdf_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void read_file(int fd)
{
    char *line;

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

    *map = malloc(n_rows * sizeof(t_point *));
    if (!*map)
        return ;
    while (i < n_rows)
    {
        (*map)[i] = malloc(n_cols * sizeof(t_point));
        if (!(*map)[i])
            return ;
        i++;
    }
}

void    parse_map(int fd)
{
    t_point **map;
    char    *line;
    char    **pline;
    int     x;
    int     y;
    y = 0;
    mem_map(fd, &map);
    while ((line = get_next_line(fd)) != NULL) {
        pline = ft_split(line, ' ');
        x = 0;
        while(pline[x] != NULL)
        {
            map[y][x].z = ft_atoi(pline[x]);
            x++;
        }
        y++;
        free(pline);
        free(line);
    }
    ft_printf("Parseado correctamente... enserio?");
}
