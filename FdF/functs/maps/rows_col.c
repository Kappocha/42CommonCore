#include "../../fdf_header.h"
#include <stdio.h>
#include <unistd.h>

int count_rows(int fd)
{
    char    *line;
    int y;

    y = 0;
    lseek(fd, 0, SEEK_SET);
    line = get_next_line(fd);
    while (line != NULL) {
        free(line);
        y++;
        line = get_next_line(fd);
    }
    return (y);
}
int count_cols(int fd)
{
    char    *line;
    char    **pline;
    int x;
    int     len;

    x = 0;
    lseek(fd, 0, SEEK_SET);
    line = get_next_line(fd);
    len = ft_strlen(line);
    if (line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }
    pline = ft_split(line, ' ');
    while (pline[x])
    {
        free(pline[x]);
        x++;
    }
    free(pline);
    free(line);
    return (x);
}
