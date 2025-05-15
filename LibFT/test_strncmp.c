#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *s1 = "Hola123";
    char *s2 = "Hola124";
    char *s3 = "Hola";
    char *s4 = "Holanda";
    char *s5 = "";
    char *s6 = "";

    printf("Caso 1: %d\n", ft_strncmp(s1, s2, 7));  // Diferencia en el último carácter
    printf("Caso 2: %d\n", ft_strncmp(s1, s3, 4));  // Iguales en los primeros 4
    printf("Caso 3: %d\n", ft_strncmp(s3, s4, 10)); // s3 es prefijo de s4
    printf("Caso 4: %d\n", ft_strncmp(s5, s6, 3));  // Ambos vacíos
    printf("Caso 5: %d\n", ft_strncmp("ABC", "abc", 3)); // Diferencia por mayúsculas/minúsculas

    return 0;
}

