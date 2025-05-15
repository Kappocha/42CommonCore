#include "libft.h"
#include <stdio.h>

int main(void)
{
    const char *s = "Hola mundo!";
    char c;
    char *res;

    // Caso 1: buscar 'm' que está en la cadena
    c = 'm';
    res = ft_strchr(s, c);
    if (res)
        printf("Encontrado '%c' en \"%s\" en posición: %ld\n", c, s, res - s);
    else
        printf("No encontrado '%c' en \"%s\"\n", c, s);

    // Caso 2: buscar 'z' que no está
    c = 'z';
    res = ft_strchr(s, c);
    if (res)
        printf("Encontrado '%c' en \"%s\" en posición: %ld\n", c, s, res - s);
    else
        printf("No encontrado '%c' en \"%s\"\n", c, s);

    // Caso 3: buscar '\0' (fin de cadena)
    c = '\0';
    res = ft_strchr(s, c);
    if (res)
        printf("Encontrado terminador nulo '\\0' en \"%s\" en posición: %ld\n", s, res - s);
    else
        printf("No encontrado terminador nulo '\\0' en \"%s\"\n", s);

    return 0;
}
