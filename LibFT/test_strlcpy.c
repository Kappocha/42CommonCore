#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest[10];
    size_t res;

    // Caso 1: Copiar una cadena corta en un buffer suficientemente grande
    res = ft_strlcpy(dest, "Hola", sizeof(dest));
    printf("Resultado: %zu, dest: '%s'\n", res, dest);

    // Caso 2: Copiar una cadena más larga que el buffer
    res = ft_strlcpy(dest, "Esta cadena es muy larga", sizeof(dest));
    printf("Resultado: %zu, dest: '%s'\n", res, dest);

    // Caso 3: buffer tamaño 0 (no se copia nada, sólo se calcula longitud)
    res = ft_strlcpy(dest, "Prueba", 0);
    printf("Resultado: %zu, dest: '%s'\n", res, dest);

    // Caso 4: copiar cadena vacía
    res = ft_strlcpy(dest, "", sizeof(dest));
    printf("Resultado: %zu, dest: '%s'\n", res, dest);

    return 0;
}

