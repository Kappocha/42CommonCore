#include <fcntl.h>     // Para open
#include <stdlib.h>    // Para free, exit
#include <stdio.h>     // Para printf
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir archivo");
		return (1);
	}

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);  // Ojo: la línea ya contiene el '\n'
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
}
