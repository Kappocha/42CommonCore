#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *original;
    char *copy;

    // Caso 1: string normal
    original = "Hola mundo";
    copy = ft_strdup(original);
    if (copy)
    {
        printf("Original: '%s'\n", original);
        printf("Copia:    '%s'\n\n", copy);
        free(copy);
    }

    // Caso 2: string vacío
    original = "";
    copy = ft_strdup(original);
    if (copy)
    {
        printf("Original: '%s'\n", original);
        printf("Copia:    '%s'\n\n", copy);
        free(copy);
    }

    // Caso 3: string con espacios y caracteres especiales
    original = "  Espacios\t y\nnuevas líneas  ";
    copy = ft_strdup(original);
    if (copy)
    {
        printf("Original: '%s'\n", original);
        printf("Copia:    '%s'\n", copy);
        free(copy);
    }

    return 0;
}

