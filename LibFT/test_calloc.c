#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    size_t count;
    size_t size;
    char *ptr_std;
    char *ptr_ft;
    int i;

    count = 5;
    size = sizeof(char);

    // Reservamos memoria con calloc estándar
    ptr_std = calloc(count, size);
    // Reservamos memoria con tu ft_calloc
    ptr_ft = ft_calloc(count, size);

    // Mostramos los valores de cada byte
    i = 0;
    while (i < 5)
    {
        printf("Índice %d: calloc = %d, ft_calloc = %d\n", i, ptr_std[i], ptr_ft[i]);
        i++;
    }

    // Liberamos la memoria
    free(ptr_std);
    free(ptr_ft);

    return 0;
}
