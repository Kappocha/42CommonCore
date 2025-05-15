#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// Función auxiliar: convierte letras minúsculas en mayúsculas según su posición
char    map_function(unsigned int i, char c)
{
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return (c - 32);  // Minúscula a mayúscula
    return (c);
}

int main(void)
{
    char *original = "hola mundo";
    char *modificada;

    modificada = ft_strmapi(original, map_function);
    if (!modificada)
    {
        printf("Error: ft_strmapi devolvió NULL\n");
        return (1);
    }

    printf("Original  : %s\n", original);
    printf("Modificada: %s\n", modificada);

    free(modificada);
    return 0;
}
