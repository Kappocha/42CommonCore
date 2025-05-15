#include "libft.h"

int main(void)
{
    char *s1;
    char *s2;
    char *s3;

    s1 = "Hola mundo";
    s2 = "";
    s3 = "Esto es una prueba con salto de línea";

    ft_putendl_fd(s1, 1); // stdout
    ft_putendl_fd(s2, 1); // línea vacía
    ft_putendl_fd(s3, 1); // otra cadena

    return 0;
}
