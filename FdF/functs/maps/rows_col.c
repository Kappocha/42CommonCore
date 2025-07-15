#include "../../fdf_header.h"
#include <unistd.h>

int count_rows(int fd)
{
    char    *line;
    int y;

    y = 0;
    lseek(fd, 0, SEEK_SET);
    line = get_next_line(fd);
    while (line != NULL) {
        y++;
        free(line);
        line = get_next_line(fd);
    }
    return (y);
}
int count_cols(int fd)
{
    char    *line;
    char    **pline;
    int x;
    int i;

    x = 0;
    lseek(fd, 0, SEEK_SET);
    line = get_next_line(fd);
    pline = ft_split(line, ' ');
    i = 0;
    while (pline[i] != NULL)
    {
        x++;
        i++;
    }
    free(pline[i]);
    free(pline);
    free(line);
    return(x);
}
