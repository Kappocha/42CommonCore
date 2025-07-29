#include "../../fdf_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mem_map(int fd, t_point ***map, t_map *info) {
    int i = 0;
    (*info).cols_num = count_cols(fd);
    (*info).rows_num = count_rows(fd);
    *map = malloc((*info).rows_num * sizeof(t_point *));
    if (!(*map)) {
        return;
    }
    while (i < (*info).rows_num) {
        (*map)[i] = malloc((*info).cols_num * sizeof(t_point));
        if (!(*map)[i]) {
            free_map(*map, i);
            *map = NULL;
            return;
        }
        i++;
    }
}

void parse_map(int fd, t_point ***map, t_map *info) {
  char *line;
  int x;
  int y;
  int i;

  y = 0;
  mem_map(fd, map, info);
  lseek(fd, 0, SEEK_SET);
  line = get_next_line(fd);
  while (line != NULL)
  {
    x = 0;
    i = 0;
    while (x < (*info).cols_num)
    {
        while (line[i] == ' ')
            i++;
        (*map)[y][x].x = x;
        (*map)[y][x].y = y;
        (*map)[y][x].z = ft_atoi(&line[i]);
        while (line[i] && line[i] != ' ')
            i++;
        x++;
    }
    free(line);
    y++;
    line = get_next_line(fd);
  }
}
