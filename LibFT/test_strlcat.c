#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest[20];
    size_t res;

    // Caso 1: concatenación normal
    strcpy(dest, "Hola");
    res = ft_strlcat(dest, " mundo", sizeof(dest));
    printf("Resultado: %zu, dest: '%s'\n", res, dest);

    // Caso 2: buffer pequeño (no suficiente para concatenar todo)
    strcpy(dest, "Hola");
    res = ft_strlcat(dest, " mundo muy largo", 10);
    printf("Resultado: %zu, dest: '%s'\n", res, dest);

    // Caso 3: buffer justo para concatenar
    strcpy(dest, "Hola");
    res = ft_strlcat(dest, "!", 6);
    printf("Resultado: %zu, dest: '%s'\n", res, dest);

    // Caso 4: buffer tamaño 0
    strcpy(dest, "Hola");
    res = ft_strlcat(dest, " mundo", 0);
    printf("Resultado: %zu, dest: '%s'\n", res, dest);

    return 0;
}

