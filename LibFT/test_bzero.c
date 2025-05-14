#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char buffer1[10];
    char buffer2[10];
    int i;

    // Inicializamos ambos buffers con caracteres no nulos
    i = 0;
    while (i < 10)
    {
        buffer1[i] = 'A';
        buffer2[i] = 'A';
        i++;
    }

    // Aplicamos bzero (original y ft_)
    bzero(buffer1, 5);      // Función original de libc
    ft_bzero(buffer2, 5);   // Tu implementación

    // Mostramos ambos resultados para comparación
    i = 0;
    while (i < 10)
    {
        printf("Pos %d: original = %d, ft_ = %d\n", i, buffer1[i], buffer2[i]);
        i++;
    }

    return 0;
}
