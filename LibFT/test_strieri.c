#include "libft.h"
#include <stdio.h>

// Función que convierte la letra en mayúscula si el índice es par
void to_upper_even(unsigned int i, char *c)
{
    (void)i; // por si no usamos el índice
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c = *c - 32; // minus a mayus
}

int main(void)
{
    char str[] = "holamundO!";

    printf("Antes: %s\n", str);
    ft_striteri(str, to_upper_even);
    printf("Después: %s\n", str);

    return 0;
}

